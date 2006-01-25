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

#include <stdlib.h>
#include <errno.h>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#define MAX_FILE_LENGTH 20000


// Callback must be declared static, otherwise it won't link...
size_t WriteCallback(char* ptr, size_t size, size_t nmemb, void *f)
{
  FILE *file = (FILE *)f;
  return fwrite(ptr, size, nmemb, file);
};


int main(int argc, char *argv[])
{
  if(argc < 2) {
    std::cerr << "Example 11: Wrong number of arguments" << std::endl 
	      << "Example 11: Usage: example11 url [file]" 
	      << std::endl;
    return EXIT_FAILURE;
  }
  char *url = argv[1];
  char *filename = NULL;
  if(argc >= 3) {
    filename = argv[2];
  }
  
  try {
    cURLpp::Cleanup cleaner;
    cURLpp::Easy request;
    
    // Set the writer callback to enable cURL 
    // to write result in a memory area
    cURLpp::OptionTrait< curl_write_callback, CURLOPT_WRITEFUNCTION > 
      myFunction(WriteCallback);

    FILE *file = stdout;
    if(filename != NULL) {
      file = fopen(filename, "wb");
      if(file == NULL) {
	fprintf(stderr, strerror(errno));
	return EXIT_FAILURE;
      }
    } 

    cURLpp::OptionTrait< void *, CURLOPT_WRITEDATA > 
      myData(file);

    request.setOpt(myFunction);
    request.setOpt(myData);
    
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
