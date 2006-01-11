/*
 *    Copyright (c) <2002-2006> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_OPTIONBASE_HPP
#define CURLPP_OPTIONBASE_HPP

#include <curl/curl.h>

#include "dllfct.h"


namespace cURLpp
{
  class CurlHandle;

  /**
   * This is the parent of the cURLpp::option class. This is only used to be
   * able to stock a list of options.
   */
  class CURLPPAPI OptionBase
  {
  public:
    OptionBase( CURLoption option );
     
    /**
     * The destructor.
     */
    virtual ~OptionBase();
         
    /**
     * See cURLpp::option::operator< for documentation.
     */
    virtual bool operator<( const OptionBase &rhs ) const;

    /**
     * return a copy of the current option.
     */
    virtual OptionBase *clone() const = 0;

    /**
     * return the libcurl option.
     */
    CURLoption getOption() const;

    /**
     * will update the value of the option with the value of the
     * option passed is argument.
     */
    virtual void updateMeToOption(const OptionBase &other) = 0;

    /**
     * will call the actual libcurl option function with the value we got 
     * on the handle.
     */
    virtual void updateHandleToMe(cURLpp::CurlHandle *handle) const = 0;

    /**
     * this function will reset the option value.
     */
    virtual void clear() = 0;

  private:
    CURLoption mOption;
  };
}
   
#endif
