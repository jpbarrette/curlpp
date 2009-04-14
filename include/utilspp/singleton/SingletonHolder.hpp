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

#ifndef SINGLETON_HOLDER_HPP
#define SINGLETON_HOLDER_HPP

#include <cassert>

#include "CreationUsingNew.hpp"
#include "LifetimeDefault.hpp"
#include "LifetimeWithLongevity.hpp"
#include "../ThreadingSingle.hpp"

namespace utilspp
{
  template
  <class T,
    template <class> class CreationPolicy = utilspp::CreationUsingNew,
    template <class> class LifetimePolicy = utilspp::LifetimeDefault,
    template <class> class ThreadingModel = utilspp::ThreadingSingle>
  class SingletonHolder
  {
  public:
    //the accessor method.
    static T & instance();
    static void makeInstance();
    static void terminate();
         
  protected:
    //protected to be sure that nobody may create one by himself.
    SingletonHolder();
         
  private:
    static void destroySingleton();
         
  private:
    typedef typename ThreadingModel<T *>::VolatileType InstanceType;
    static InstanceType mInstance;
    static bool mDestroyed;
  };

}

//#ifdef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
	#include "SingletonHolder.inl"
//#endif

#endif
