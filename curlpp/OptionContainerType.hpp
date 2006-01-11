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

#ifndef OPTION_CONTAINER_TYPE_HPP
#define OPTION_CONTAINER_TYPE_HPP

#include <string>
#include <list>

#include "SList.hpp"
#include "Form.hpp"
#include "Types.hpp"

namespace cURLpp
{
  template< typename OptionType >
  struct OptionContainerType
  {
    // The type of the parameter of setOpt.
    typedef const OptionType &ParamType;

    // The type of the value kept in the option class.
    typedef OptionType ValueType;

    // The type of the value returned by getValue function.
    typedef OptionType ReturnType;

    /**
     * This typedef is the type usable by the OptionSetter::setOpt to
     * eventually call curl_easy_setopt().
     */
    typedef OptionType &HandleOptionType;
  };

  template< typename OptionType >
  struct OptionContainerType< OptionType * >
  {
    // The type of the parameter of setOpt.
    typedef OptionType *ParamType;

    // The type of the value kept in the option class.
    typedef OptionType *ValueType;

    // The type of the value returned by getValue function.
    typedef OptionType *ReturnType;

    /**
     * This typedef is the type usable by the OptionSetter::setOpt to
     * eventually call curl_easy_setopt().
     */
    typedef OptionType *HandleOptionType;
  };

  template< >
  struct OptionContainerType< std::string >
  {
  public:
    typedef const std::string &ParamType;
    typedef std::string ValueType;
    typedef std::string ReturnType;
    typedef const std::string &HandleOptionType;
  };

  template< >
  struct OptionContainerType< std::list< std::string > >
  {
  public:
    typedef const std::list< std::string > &ParamType;
    typedef cURLpp::SList ValueType;
    typedef std::list< std::string > ReturnType;
    typedef const cURLpp::SList &HandleOptionType;
  };

  template< >
  struct OptionContainerType< std::list< cURLpp::FormPart * > >
  {
    typedef const std::list< cURLpp::FormPart * > &ParamType;
    typedef cURLpp::HttpPost ValueType;
    typedef std::list< cURLpp::FormPart * > ReturnType;
    typedef const cURLpp::HttpPost &HandleOptionType;
  };
}


#endif 
