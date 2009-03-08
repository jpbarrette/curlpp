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

#ifndef LIFETIME_LIBRARY_HPP
#define LIFETIME_LIBRARY_HPP

#include <cassert>

#include "PrivateMembers.hpp"
#include "CreationUsingNew.hpp"

namespace utilspp
{
   
   template<typename T>
   unsigned int getLongevity(T * p);

   /**
    * Assigns an object a longevity. Ensures ordered destructions of objects
    * registered thusly during the exit sequence of the application.
    */
   template<typename T, typename TDestroyer>
      void setLibraryLongevity( 
            T * obj, 
            unsigned int longevity, 
            TDestroyer d = utilspp::PrivateMembers::Deleter<T>::deleteObject
            );

  /**
   * This class is a lifetime policy for the singleton. This
   * class allow you to terminate the singleton explicitly. 
   * You can terminate by calling:
   *
   * LifetimeLibrarySingleton::instance().terminate()
   *
   * This singleton use the utilspp::LifetimeWithLongevity policy.
   */
  template<typename T>
  struct LifetimeLibrary
  {
    static void scheduleDestruction(T * obj, void (* func)());
    static void onDeadReference();
  };
  
  class LifetimeLibraryImpl
  {
  public:
    LifetimeLibraryImpl();
    ~LifetimeLibraryImpl();
    
    void add(utilspp::PrivateMembers::LifetimeTracker * tracker);
    void terminate();
    
  private:
    utilspp::PrivateMembers::TrackerArray mTrackerArray;
    int mNbElements;
  };
  
  unsigned int getLongevity(utilspp::LifetimeLibraryImpl * p);

  typedef utilspp::SingletonHolder< 
    utilspp::LifetimeLibraryImpl,
    utilspp::CreationUsingNew,  
    utilspp::LifetimeWithLongevity
    > LifetimeLibrarySingleton;

  /**
   * This class will ensure that 
   *
   * LifetimeLibraryImpl::terminate() 
   *
   * is called.
   */
  template<typename T = utilspp::LifetimeLibrarySingleton>
  class LifetimeLibraryGuard
  {
  public:
    ~LifetimeLibraryGuard();
  };
}

//#ifdef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
	#include "LifetimeLibrary.inl"
//#endif

#endif
