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

#include <iostream>

#include "curlpp/global.h"
#include "curlpp/OptionList.hpp"


cURLpp::OptionList::OptionList()
{}

cURLpp::OptionList::OptionList( const cURLpp::OptionList &rhs )
{
   insert( rhs.mOptions );
}

cURLpp::OptionList::~OptionList()
{
  mapType::iterator pos = mOptions.begin();
  while (pos != mOptions.end()) {
    delete (*pos).second;
    pos++;
  }
}


void cURLpp::OptionList::setOpt( cURLpp::OptionBase *option )
{
   mapType::iterator pos = mOptions.find(option->getOption());
   if( pos != mOptions.end() )
   {
      delete (*pos).second;
      mOptions.erase(pos);	
   }
   mOptions.insert(std::make_pair(option->getOption(), option));
}


void cURLpp::OptionList::setOpt(const cURLpp::OptionList &options)
{
  for(mapType::const_iterator pos = options.mOptions.begin();
      pos != options.mOptions.end();
      pos++)
   {
     setOpt(pos->second->clone());
   }  
}


void
cURLpp::OptionList::setOpt( const cURLpp::OptionBase &option )
{
   setOpt(option.clone());
}


void
cURLpp::OptionList::getOpt(cURLpp::OptionBase *option) const
{
   mapType::const_iterator pos = mOptions.find(option->getOption());
   if( pos != mOptions.end() )
   {
      option->updateMeToOption((*(*pos).second));
   }
   else
   {
      option->clear();
   }
}


void
cURLpp::OptionList::insert( const cURLpp::OptionList::mapType &other )
{
    for( mapType::const_iterator pos = other.begin();
         pos != other.end();
         pos++)
   {
      mOptions.insert(std::make_pair(pos->second->getOption(), pos->second->clone()));
   }
}


