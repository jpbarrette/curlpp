/*
 *    Copyright (c) <2002-2009> <Jean-Philippe Barrette-LaPierre>
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

#ifndef LIFETIME_WITH_LONGEVITY_HPP
#define LIFETIME_WITH_LONGEVITY_HPP

#include <cassert>
#include <algorithm>
#include "PrivateMembers.hpp"

namespace utilspp
{
   
   template<typename T>
   unsigned int getLongevity(T * p);

   /**
    * Assigns an object a longevity. Ensures ordered destructions of objects
    * registered thusly during the exit sequence of the application.
    */
  template<typename T, typename TDestroyer>
  void setLongevity(T * obj, 
		    unsigned int longevity, 
		    TDestroyer d = utilspp::PrivateMembers::Deleter<T>::deleteObject);
  
  template<typename T>
  struct LifetimeWithLongevity
  {
    static void scheduleDestruction(T * obj, void (* func)());
    static void onDeadReference();
  };
}

//#ifdef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
	#include "LifetimeWithLongevity.inl"
//#endif

#endif
