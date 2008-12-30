/*
 *    Copyright (c) <2002-2006> <Jean-Philippe Barrette-LaPierre>
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

#ifndef OPTION_CONTAINER_INL
#define OPTION_CONTAINER_INL

template<class OptionType>
curlpp::internal::OptionContainer<OptionType>
::OptionContainer(typename curlpp::internal::OptionContainer<OptionType>::ParamType value)
: mValue(value)
{}


template<class OptionType>
curlpp::internal::OptionContainer<OptionType>
::OptionContainer(curlpp::internal::OptionContainer<OptionType> & other) 
: mValue(other.mValue)
{}


template<class OptionType>
void
curlpp::internal::OptionContainer<OptionType>
::setValue(typename internal::OptionContainer<OptionType>::ParamType value)
{
  mValue = value;
}

template<class OptionType>
typename curlpp::internal::OptionContainer<OptionType>::ReturnType
curlpp::internal::OptionContainer<OptionType>::getValue()
{
  return mValue;
}

template<class OptionType>
typename curlpp::internal::OptionContainer<OptionType>::HandleOptionType
curlpp::internal::OptionContainer<OptionType>::getHandleOptionValue()
{
  return mValue;
}

#endif
