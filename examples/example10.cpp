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

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

using namespace std;

using namespace cURLpp;
using namespace cURLpp::Options;


#define MAX_FILE_LENGTH 20000

size_t 
FileCallback(FILE *f, char* ptr, size_t size, size_t nmemb)
{
  return fwrite(ptr, size, nmemb, f);
};


int main(int argc, char *argv[])
{
  if(argc != 3) {
    cerr << argv[0] << ": Wrong number of arguments" << endl 
	      << argv[0] << ": Usage: " << " url file" 
	      << endl;

    return EXIT_FAILURE;
  }

  char *url = argv[1];
  char *filename = argv[2];
  FILE * file = fopen(filename, "w");
  if (!file)
  {
    cerr << "Error opening " << filename << endl;
    return EXIT_FAILURE;
  }
  
  try {
    Cleanup cleaner;
    Easy request;
    
    // Set the writer callback to enable cURL 
    // to write result in a memory area
    Types::WriteFunctionFunctor functor(utilspp::BindFirst(utilspp::make_functor(&FileCallback), file));
    WriteFunction *test = new WriteFunction(functor);
    request.setOpt(test);
    
    // Setting the URL to retrive.
    request.setOpt(new Url(url));
    request.setOpt(new Verbose(true));
    request.perform();

    return EXIT_SUCCESS;
  }
  catch ( LogicError & e ) {
    cout << e.what() << endl;
  }
  catch ( RuntimeError & e ) {
    cout << e.what() << endl;
  }

  return EXIT_FAILURE;
}
