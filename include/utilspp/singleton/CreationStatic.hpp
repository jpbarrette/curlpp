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

#ifndef CREATION_STATIC_HPP
#define CREATION_STATIC_HPP

/**
 * This class is a creation policy for the utilspp::singleton_holder. The
 * policy is creating the singleton by a static memory. The constructor is
 * called the first time we call the utilspp::creation_static::create()
 * function.
 *
 * This creation policy is very usefull since it rely on static allocation.
 * It means that the creation is automatically thread-safe, since compilers
 * static ensures that static allocation is thread-safe.
 *
 * Note don't use this class with a lifetime policy that allows revivals. 
 * Be carefull with this policy since it won't respect the lifetime policy.
 * It will eventually be destroyed, but at the end of the program. 
 */
namespace utilspp
{
   template<typename T>
   class CreationStatic
   {
      public:
         static T* create();
         static void destroy(T* obj);
   };
}

//#ifdef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
	#include "CreationStatic.inl"
//#endif

#endif
