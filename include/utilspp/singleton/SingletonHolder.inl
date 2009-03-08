/*
 *    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
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

#ifndef SINGLETON_HOLDER_INL
#define SINGLETON_HOLDER_INL

template
<
class T,
template <class> class CreationPolicy,
template <class> class LifetimePolicy,
template <class> class ThreadingModel
>
T&
utilspp::SingletonHolder
<
T,
CreationPolicy,
LifetimePolicy,
ThreadingModel
>
::instance()
{
    if (mInstance == NULL)
    {
        makeInstance();
    }

    return (*mInstance);
};

template
<
  class T,
  template <class> class CreationPolicy,
  template <class> class LifetimePolicy,
  template <class> class ThreadingModel
  >
void
utilspp::SingletonHolder
<
  T,
  CreationPolicy,
  LifetimePolicy,
  ThreadingModel
  >::makeInstance()
{
  if (mInstance == NULL)
  {
    typename ThreadingModel<T>::lock guard;
    (void)guard;
    
    if (mInstance == NULL) {
      if (mDestroyed)
      {
        LifetimePolicy<T>::onDeadReference();
        mDestroyed = false;
      }
      
      mInstance = CreationPolicy<T>::create();
      LifetimePolicy<T>::scheduleDestruction(mInstance, & destroySingleton);
    }
  }
}

template
<
class T,
template <class> class CreationPolicy,
template <class> class LifetimePolicy,
template <class> class ThreadingModel
>
void
utilspp::SingletonHolder
<
T,
CreationPolicy,
LifetimePolicy,
ThreadingModel
>
::destroySingleton()
{
    assert(!mDestroyed);
    CreationPolicy<T>::destroy(mInstance);
    mInstance = NULL;
    mDestroyed = true;
}

template <class T,
template <class> class C,
template <class> class L,
template <class> class M
>
typename utilspp::SingletonHolder<T, C, L, M>::InstanceType
utilspp::SingletonHolder<T, C, L, M>::mInstance;

template
<
class T,
template <class> class C,
template <class> class L,
template <class> class M
>
bool utilspp::SingletonHolder<T, C, L, M>::mDestroyed;

#endif
