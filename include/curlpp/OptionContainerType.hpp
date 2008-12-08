/*
 *    Copyright (c) <2002-2008> <Jean-Philippe Barrette-LaPierre>
 *    
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files 
 *    (curlpp), to deal in the Software without restriction, 
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

#ifndef CURLPP_OPTION_CONTAINER_TYPE_HPP
#define CURLPP_OPTION_CONTAINER_TYPE_HPP

#include <string>
#include <list>

#include "SList.hpp"
#include "Form.hpp"
#include "Types.hpp"

namespace curlpp
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
    typedef curlpp::SList ValueType;
    typedef std::list< std::string > ReturnType;
    typedef const curlpp::SList &HandleOptionType;
  };

  template< >
  struct OptionContainerType< curlpp::Forms >
  {
    typedef const Forms &ParamType;
    typedef curlpp::HttpPost ValueType;
    typedef Forms ReturnType;
    typedef const curlpp::HttpPost &HandleOptionType;
  };

//   template< >
//   struct OptionContainerType< std::ostream * >
//   {
//     typedef const std::list< curlpp::FormPart * > &ParamType;
//     typedef curlpp::HttpPost ValueType;
//     typedef std::list< curlpp::FormPart * > ReturnType;
//     typedef const curlpp::HttpPost &HandleOptionType;
//   };

} // namespace curlpp

namespace cURLpp = curlpp;

#endif // #ifndef CURLPP_OPTION_CONTAINER_TYPE_HPP
