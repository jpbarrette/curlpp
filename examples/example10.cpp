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

#include <stdio.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#define MAX_FILE_LENGTH 20000

size_t 
FileMemoryCallback(FILE *f, char* ptr, size_t size, size_t nmemb)
{
  return fwrite(ptr, size, nmemb, f);
};


int main(int argc, char *argv[])
{
  if(argc != 2) {
    std::cerr << "Example 06: Wrong number of arguments" << std::endl 
	      << "Example 06: Usage: example06 url" 
	      << std::endl;

    return EXIT_FAILURE;
  }
  char *url = argv[1];
  
  try {
    cURLpp::Cleanup cleaner;
    cURLpp::Easy request;
    
    // Set the writer callback to enable cURL 
    // to write result in a memory area
    FILE *myfd = stdout;
    utilspp::Functor< size_t, TYPE_LIST_4(FILE *, char *, size_t, size_t) > myFunctor(&FileMemoryCallback);
    utilspp::BindFirst(myFunctor, myfd);
    utilspp::Functor< size_t, TYPE_LIST_3(char *, size_t, size_t) > test3(utilspp::BindFirst(myFunctor, stdout));
    cURLpp::Types::WriteFunctionFunctor functor(utilspp::BindFirst(myFunctor, stdout));
    cURLpp::Options::WriteFunction *test = new cURLpp::Options::WriteFunction(functor);
    request.setOpt(test);
    
    // Setting the URL to retrive.
    request.setOpt(new cURLpp::Options::Url(url));
    request.setOpt(new cURLpp::Options::Verbose(true));
    request.perform();
  }
  catch ( cURLpp::LogicError & e ) {
    std::cout << e.what() << std::endl;
  }
  catch ( cURLpp::RuntimeError & e ) {
    std::cout << e.what() << std::endl;
  }
}
