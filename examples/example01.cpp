/*
 *    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (cURLpp), to deal in the Software without restriction, 
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

#include <string>
#include <iostream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

#define MY_PORT 8080


/** 
 * This example is made to show you how you can use the Options.
 */
int main(int, char **)
{
  try
    {
      cURLpp::Cleanup myCleanup;

      // Creation of the URL option.
      cURLpp::Options::Url myUrl(std::string("http://example.com"));
      
      // Copy construct from the other URL.
      cURLpp::Options::Url myUrl2(myUrl);

      // Creation of the port option.
      cURLpp::Options::Port myPort(MY_PORT);

      // Creation of the request.
      cURLpp::Easy myRequest;


      // Creation of an option that contain a copy of the URL option.
      cURLpp::OptionBase *mytest = myUrl.clone();
      myRequest.setOpt(*mytest);

      // You can reuse the base option for other type of option
      // and set the option to the request. but first, don't forget 
      // to delete the previous memory. You can delete it since the 
      // option is internally duplicated for the request.
      delete mytest;
      mytest = myPort.clone();
      myRequest.setOpt(*mytest);
      delete mytest;

      // You can clone an option directly to the same type of 
      // option.
      cURLpp::Options::Url *myUrl3 = myUrl.clone();
      myRequest.setOpt(myUrl3);
      // Now myUrl3 is owned by the request we will NOT use 
      // it anymore.


      // You don't need to declare an option if you just want 
      // to use it once.
      myRequest.setOpt(cURLpp::Options::Url("example.com"));
      

      // Note that the previous line wasn't really efficient
      // because we create the option, this option is duplicated
      // for the request and then the option destructor is called.
      // You can use this instead:
      myRequest.setOpt(new cURLpp::Options::Url("example.com"));
      // Note that with this the request will use directly this
      // instance we just created. Be aware that if you pass an
      // Option pointer to the setOpt function, it will consider
      // the instance has its own instance. The Option instance
      // will be deleted when the request will be deleted, so
      // don't use the instance further in your code.


      // Doing the previous line is efficient as this:
      myRequest.setOpt(myUrl.clone());

      
      // You can retreive the value of a specific option.
      std::cout << myUrl2.getValue() << std::endl;

      // Perform the transaction with the options set.
      myRequest.perform();
    }
  catch( cURLpp::RuntimeError &e )
    {
      std::cout << e.what() << std::endl;
    }
  catch( cURLpp::LogicError &e )
    {
      std::cout << e.what() << std::endl;
    }
    
  return 0;
}
