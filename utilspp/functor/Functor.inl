/*
 *    Copyright (c) <2002-2005> <Jean-Philippe Barrette-LaPierre>
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

#ifndef UTILSPP_FUNCTOR_INL
#define UTILSPP_FUNCTOR_INL

template <typename R, class TList>
template <typename Fun>
utilspp::Functor<R, TList>::Functor(Fun fun)
: mImpl(new FunctorHandler< Functor, Fun >(fun))
{}

template <typename R, class TList>
template <typename PointerToObj, typename MemFun>
utilspp::Functor<R, TList>::Functor(const PointerToObj &obj, MemFun fun)
: mImpl(new MemFunHandler< Functor, PointerToObj, MemFun >(obj, fun))
{}

template <typename R, class TList>
utilspp::Functor<R, TList>::Functor(const Functor &functor)
: mImpl(functor.mImpl->clone())
{}

template <typename R, class TList>
utilspp::Functor<R, TList> &
utilspp::Functor<R, TList>::operator=(const Functor &functor)
{
  mImpl = std::auto_ptr< Impl >(functor.mImpl->clone());
  return (*this);
}

#endif

