/*
*    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
*    
*    Permission is hereby granted, free of charge, to any person obtaining
*    a copy of this software and associated documentation files 
*    (curlpp), to deal in the Software without restriction, 
*    including without limitation the rights to use, copy, modify, merge,
*    publish, distribute, sublicense, and/or sell copies of the Software,
*    and to permit persons to whom the Software is furnished to do so, 
*    subject to the following conditions:
*    
*    The above copyright notice and this permission notice shall be included
*    in all copies or substantial portions of the Software.
*    
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*    OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
*    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
*    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
*    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*    SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/**
* \file
* Send e-mail with SMTP.
*/


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
 
/*
   anonymous namespace to prevent name clash in case other examples using the same global entities
   would be compiled in the same project
*/
namespace
{

// Change those to appropriate values:
const std::string smtpUrl = "smtp://mail.example.com";
const std::string fromAddress = "<sender@example.org>";
const std::string toAddress = "<addressee@example.net>";
const std::string ccAddress = "<info@example.org>";
const std::string fromMail = "Sender Person " + fromAddress;
const std::string toMail = "A Receiver " + toAddress;
const std::string ccMail = "John CC Smith " + ccAddress;
const std::string mailDate = "Wed, 28 Aug 2019 16:26:00 +0300";
const std::string mailSubject = "SMTP example message";
const std::string mailText = "Hi there,\r\n\r\nThis is a message from curlpp!\r\n";

} // namespace

int main(int argc, char *argv[])
{
	std::stringstream dataStream;
	dataStream 
		<< "Date: " << mailDate << "\r\n"
		<< "To: " << toMail << "\r\n"
		<< "From: " << fromMail << "\r\n"
		<< "Cc: " << ccMail << "\r\n"
		<< "Subject: " << mailSubject << "\r\n"
		<< "\r\n"
		<< mailText;
	long size = dataStream.str().size();

	std::list<std::string> recepients;
	recepients.push_back(toAddress);
	recepients.push_back(ccAddress);

	try
	{
		curlpp::Cleanup cleaner;
		curlpp::Easy request;

		using namespace curlpp::Options;
		request.setOpt(new Verbose(true));
		request.setOpt(new Url(smtpUrl));
		request.setOpt(new MailFrom(fromAddress));
		request.setOpt(new MailRcpt(recepients));
		request.setOpt(new ReadStream(&dataStream));
		request.setOpt(new InfileSize(size));
		request.setOpt(new Upload(true));

		request.perform();
	}
	catch (curlpp::LogicError & e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (curlpp::RuntimeError & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

