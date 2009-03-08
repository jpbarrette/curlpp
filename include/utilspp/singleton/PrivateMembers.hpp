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

#ifndef PRIVATE_MEMBERS_HPP
#define PRIVATE_MEMBERS_HPP

#include <cassert>

namespace utilspp
{
  namespace PrivateMembers
  {
    /**
     * Helper class for utils::setLongevity
     */
    class LifetimeTracker
    {
    public:
      LifetimeTracker(unsigned int longevity);
      virtual ~LifetimeTracker();
      static bool compare( 
			  const LifetimeTracker * l, 
			  const LifetimeTracker * r
			  );

    private:
      unsigned int mLongevity;
    };

    typedef LifetimeTracker** TrackerArray;

    extern TrackerArray mTrackerArray;
    extern int mNbElements;

    /**
     * Helper class for Destroyer
     */
    template<typename T>
    struct Deleter
    {
      void deleteObject(T * obj);
    };

    /**
     * Concrete lifetime tracker for objects of type T
     */
    template<typename T, typename TDestroyer>
    class ConcreteLifetimeTracker : public LifetimeTracker
    {
    public:
      ConcreteLifetimeTracker(T * obj, unsigned int longevity, TDestroyer d);
       
      ~ConcreteLifetimeTracker();
      
    private:
      T* mTracked;
      TDestroyer mDestroyer;
    };
    
    void atExitFunc();
    
    template <class T>
    struct adapter
    {
      void operator()(T*);
      void (* mFunc)();
    };
  }
}

//#ifdef CURLPP_INCLUDE_TEMPLATE_DEFINITIONS
	#include "PrivateMembers.inl"
//#endif

#endif
