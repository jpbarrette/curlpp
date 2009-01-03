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

#ifndef CURLPP_OPTION_INL
#define CURLPP_OPTION_INL

#include <iostream>
#include "curlpp/internal/OptionSetter.hpp"
#include "curlpp/Exception.hpp"


template<typename OptionType>
curlpp::Option<OptionType>::Option(CURLoption option, typename curlpp::Option<OptionType>::ParamType value)
: OptionBase(option),
mContainer(NULL)
{
	setValue(value);
}


template<typename OptionType>
curlpp::Option<OptionType>::Option(CURLoption option)
: OptionBase(option),
mContainer(NULL)
{}

template<typename OptionType>
curlpp::Option<OptionType>::Option(const curlpp::Option<OptionType> & other)
  : OptionBase(other)
  , mContainer(NULL)
{
	if(other.mContainer != NULL)	
	{
		setValue(other.getValue());
	}
}


template<typename OptionType>
curlpp::Option<OptionType>::~Option()
{
	delete mContainer;
	mContainer = NULL;
}


template<typename OptionType>
void
curlpp::Option<OptionType>::setValue(typename curlpp::Option<OptionType>::ParamType value)
{
	if(mContainer == NULL)
	{	
		mContainer = new internal::OptionContainer<OptionType>(value);
	}
	else
	{
		mContainer->setValue(value);
	}
}


template<typename OptionType>
void
curlpp::Option<OptionType>::updateMeToOption(const curlpp::OptionBase & other)
{
	const curlpp::Option<OptionType> * option = dynamic_cast<const curlpp::Option<OptionType> *>(&other);
	if(option == NULL)
	{
		throw UnsetOption("You are trying to update an option to an incompatible option");
	}
	setValue(option->getValue());
}

template<typename OptionType>
void
curlpp::Option<OptionType>::clear()
{
  delete mContainer;
  mContainer = NULL;
}

template<typename OptionType>
typename curlpp::Option<OptionType>::ReturnType
curlpp::Option<OptionType>::getValue() const
{
  if(mContainer == NULL)
    throw curlpp::UnsetOption(std::string("You are trying to retreive the value of an unset option"));

  return mContainer->getValue();
}

template<typename OptionType, CURLoption option>
curlpp::OptionTrait<OptionType, option>::OptionTrait(typename curlpp::Option<OptionType>::ParamType value)
: Option<OptionType>(option, value)
{}

template<typename OptionType, CURLoption option>
curlpp::OptionTrait<OptionType, option>::OptionTrait()
: Option<OptionType>(option)
{}


template<typename OptionType, CURLoption option>
curlpp::OptionTrait<OptionType, option> *
curlpp::OptionTrait<OptionType, option>::clone() const
{
  return new OptionTrait<OptionType, option>(this->getValue());
}


template<typename OptionType, CURLoption option>
void
curlpp::OptionTrait<OptionType, option>::updateHandleToMe(internal::CurlHandle * handle) const
{
	if(this->mContainer == NULL)
	{
		throw UnsetOption(std::string("You are trying to set an unset option to a handle"));
	}	

	internal::OptionSetter<OptionType, option>::setOpt(handle, this->mContainer->getHandleOptionValue());
}


template<CURLoption option>
curlpp::NoValueOptionTrait<option>::NoValueOptionTrait() 
  : OptionTrait<bool, option>(true)
{}

template<CURLoption option>
curlpp::NoValueOptionTrait<option> *
curlpp::NoValueOptionTrait<option>::clone() const
{
  return new NoValueOptionTrait<option>();
}

template<typename OptionType>
curlpp::NotAvailableOptionTrait<OptionType>::NotAvailableOptionTrait(typename curlpp::Option<OptionType>::ParamType )
  : Option<OptionType>(CURLOPT_URL)
{
  throw curlpp::NotAvailable();
}

template<typename OptionType>
curlpp::NotAvailableOptionTrait<OptionType>::NotAvailableOptionTrait()
  : Option<OptionType>(CURLOPT_URL)
{
  throw curlpp::NotAvailable();
}


template<typename OptionType>
curlpp::NotAvailableOptionTrait<OptionType> *
curlpp::NotAvailableOptionTrait<OptionType>::clone() const
{
  throw curlpp::NotAvailable();
}


template<typename OptionType>
void
curlpp::NotAvailableOptionTrait<OptionType>::updateHandleToMe(internal::CurlHandle *) const
{
  throw curlpp::NotAvailable();
}



#endif
