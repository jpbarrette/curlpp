/*
 *    Copyright (c) <2002-2005> <Gazihan Alankus>
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

#include <stdlib.h>
#include <errno.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#include <fstream>

int main(int argc, char *argv[])
{
  if(argc < 2) {
    std::cerr << argv[0] << ": Wrong number of arguments" << std::endl 
	      << "Usage: " << argv[0] << " url"
	      << std::endl;
    return EXIT_FAILURE;
  }
  
  char *url = argv[1];
  
  try {
    cURLpp::Cleanup cleaner;
    cURLpp::Easy request;
    
    request.setOpt(new cURLpp::Options::Url(url)); 
    //request.setOpt(new cURLpp::Options::Verbose(true)); 
    
    {
      // Forms takes ownership of pointers!
      cURLpp::Forms formParts;
      formParts.push_back(new cURLpp::FormParts::Content("name1", "value1"));
      formParts.push_back(new cURLpp::FormParts::Content("name2", "value2"));
      
      request.setOpt(new cURLpp::Options::HttpPost(formParts)); 
    }

    // The forms have been cloned and are valid for the request, even
    // if the original forms are out of scope.
    std::ofstream myfile("/dev/null");
    myfile << request << std::endl << request << std::endl;
  }
  catch ( cURLpp::LogicError & e ) {
    std::cout << e.what() << std::endl;
  }
  catch ( cURLpp::RuntimeError & e ) {
    std::cout << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
