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

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>
 

using namespace std;

using namespace cURLpp;


class MyWindow
{
public:
  int writeDebug(curl_infotype, char *, size_t)
  {
    raiseException(runtime_error("This is our exception."));
    cout << "We never reach this line." << endl;
    return 0;
  }
};

int main(int argc, char *argv[])
{
  if(argc != 2) {
    cerr << "Example 8: Wrong number of arguments" << endl 
	      << "Example 8: Usage: example8 url" 
	      << endl;
    return EXIT_FAILURE;
  }
  char *url = argv[1];
     
  MyWindow myWindow;
  try {
    Cleanup cleaner;
    Easy request;
    
    using namespace Options;
    request.setOpt(Verbose(true));
    request.setOpt(DebugFunction(Types::DebugFunctionFunctor(&myWindow, 
								     &MyWindow::writeDebug)));
    request.setOpt(Url(url));
    
    request.perform();
  }
  catch ( LogicError & e ) {
    cout << e.what() << endl;
  }
  catch ( RuntimeError & e ) {
    cout << e.what() << endl;
  }
  catch ( runtime_error &e ) {
    cout << e.what() << endl;
  }
  
  return 0;
}

