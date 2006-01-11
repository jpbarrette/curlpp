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

#ifndef CURLPP_EASY_HPP
#define CURLPP_EASY_HPP

#include "OptionList.hpp"
#include "CurlHandle.hpp"

namespace cURLpp
{
  class CURLPPAPI Easy : public OptionList
  {
  public: 
    friend class InfoGetter;

    Easy();
    virtual ~Easy();

    /**
     * it will call the curl_easy_perform function will all the options
     * previously set for this handle.
     */
    void perform();
	
    /**
     * This function will set the option value of the OptionBase to the 
     * handle. 
     *
     * Note: be carefull when using this function, see 
     * cURLpp::OptionList::setOpt(OptionBase *option) function for more
     * details.
     */
    virtual void setOpt(cURLpp::OptionBase *option);

    /**
     * This function will set the option value of the OptionBase
     * to the handle.
     *
     * Note: be carefull when using this function, see 
     * cURLpp::OptionList::setOpt(OptionBase *option) function for more
     * details.
     */
    virtual void setOpt(const cURLpp::OptionBase &option);

    /**
     * This function will call the setOpt on each options
     * contained by * the option list passed in argument.
     */
    virtual void setOpt(const cURLpp::OptionList &options);

    /**
     * This function will return the cURL * handle.
     * DO NOT use this, unless you REALLY know what you
     * are doing.
     */
    CURL *getHandle();

  private:
    /**
     * This is the function that cURLpp::InfoGetter will call
     * to retreive option.
     */
    template< typename T >
    void getInfo(CURLINFO info, T &value);
      
    cURLpp::CurlHandle myCurl;
  };

  #include "Easy.inl"

}


#endif
