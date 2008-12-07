/*
 *    Copyright (c) <2002-2008> <Jean-Philippe Barrette-LaPierre>
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

#include "curlpp/global.h"
#include "curlpp/buildconfig.h"

#include "curlpp/Easy.hpp"

#include "curlpp/Options.hpp"

cURLpp::Easy::Easy()
  : myCurl(new CurlHandle())
{}

cURLpp::Easy::Easy(std::auto_ptr< CurlHandle > handle)
  : myCurl(handle)
{}

cURLpp::Easy::~Easy()
{}

void 
cURLpp::Easy::perform()
{
    myCurl->perform();
}

CURL *
cURLpp::Easy::getHandle() const
{
  return myCurl->getHandle();
}

void
cURLpp::Easy::setOpt(const cURLpp::OptionBase &option)
{
    setOpt(option.clone());    
}

void
cURLpp::Easy::setOpt(cURLpp::OptionBase *option)
{
  option->updateHandleToMe(myCurl.get());
  OptionList::setOpt(option);    
}

void
cURLpp::Easy::setOpt(const cURLpp::OptionList &options)
{
    OptionList::setOpt(options);    
}

void
cURLpp::Easy::reset ()
{
  myCurl->reset();
  OptionList::setOpt(OptionList());
}


std::ostream & operator<<(std::ostream & stream, const cURLpp::Easy & request)
{
  // Quick clone that doesn't copy options, only the curl handle.
  cURLpp::Easy r(request.getCurlHandle().clone());
  r.setOpt(new cURLpp::Options::WriteStream(&stream));
  r.perform();

  return stream;
}


#if defined(CURLPP_TEMPLATE_EXPLICIT_INSTANTIATION)
	#include "Easy.ins"
#endif