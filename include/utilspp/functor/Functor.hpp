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

#ifndef UTILSPP_FUNCTOR_HPP
#define UTILSPP_FUNCTOR_HPP

#include <memory>

#include "../NullType.hpp"
#include "../EmptyType.hpp"
#include "../TypeList.hpp"
#include "../TypeTrait.hpp"

#include "FunctorImpl.hpp"
#include "FunctorHandler.hpp"
#include "MemFunHandler.hpp"

#include <memory>

namespace utilspp
{
  template<typename R, class TList>
  class Functor
  {
  public:
    typedef FunctorImpl<R, TList> Impl;

    typedef R ResultType;
    typedef TList ParmList;

    Functor(const Functor & functor) 
      : mImpl(functor.mImpl->clone())
    {}

    Functor() 
      : mImpl()
    {}

    Functor(std::unique_ptr<Impl> impl) 
      : mImpl(std::move(impl))
    {}

    Functor & operator=(const Functor & functor)
    {
      mImpl = std::unique_ptr<Impl>(std::move(functor.mImpl->clone()));
      return (*this);
    }

    template<class Fun>
    Functor(Fun fun)
      : mImpl(new FunctorHandler<Functor, Fun>(fun))
    {}

    template<class PointerToObj, class MemFun>
    Functor(const PointerToObj & obj, MemFun fun)
      : mImpl(new MemFunHandler<Functor, PointerToObj, MemFun>(obj, fun))
    {}

    bool operator!()
    {return !mImpl.get();}

    typedef typename utilspp::tl::TypeAtNonStrict<TList, 0, utilspp::EmptyType>::Result Parm1;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 1, utilspp::EmptyType>::Result Parm2;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 2, utilspp::EmptyType>::Result Parm3;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 3, utilspp::EmptyType>::Result Parm4;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 4, utilspp::EmptyType>::Result Parm5;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 5, utilspp::EmptyType>::Result Parm6;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 6, utilspp::EmptyType>::Result Parm7;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 7, utilspp::EmptyType>::Result Parm8;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 8, utilspp::EmptyType>::Result Parm9;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 9, utilspp::EmptyType>::Result Parm10;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 10, utilspp::EmptyType>::Result Parm11;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 11, utilspp::EmptyType>::Result Parm12;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 12, utilspp::EmptyType>::Result Parm13;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 13, utilspp::EmptyType>::Result Parm14;
    typedef typename utilspp::tl::TypeAtNonStrict<TList, 14, utilspp::EmptyType>::Result Parm15;

    R operator()()
    {return (*mImpl)();}

    R operator()(Parm1 p1)
    {return (*mImpl)(p1);}

    R operator()(Parm1 p1, Parm2 p2)
    {return (*mImpl)(p1, p2);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3)
    {return (*mImpl)(p1, p2, p3);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4)
    {return (*mImpl)(p1, p2, p3, p4);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5)
    {return (*mImpl)(p1, p2, p3, p4, p5);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11, Parm12 p12)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11, Parm12 p12, Parm13 p13)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11, Parm12 p12, Parm13 p13, Parm14 p14)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);}

    R operator()(Parm1 p1, Parm2 p2, Parm3 p3, Parm4 p4, Parm5 p5, Parm6 p6, Parm7 p7, Parm8 p8, Parm9 p9, Parm10 p10, Parm11 p11, Parm12 p12, Parm13 p13, Parm14 p14, Parm15 p15)
    {return (*mImpl)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);}

  private:
    std::unique_ptr<Impl> mImpl;
  };
  
  template<typename Fun>
  Functor<typename PointerOnFunction<Fun>::ReturnType, 
	   typename PointerOnFunction<Fun>::ParamList> make_functor(Fun fun)
  {
    return utilspp::Functor<typename utilspp::PointerOnFunction<Fun>::ReturnType, 
      typename utilspp::PointerOnFunction<Fun>::ParamList>(fun);
  }

  template<class MemFun>
  Functor<typename PointerOnMemberFunction<MemFun>::ReturnType, 
	   typename PointerOnMemberFunction<MemFun>::ParamList> 
  make_functor(typename PointerOnMemberFunction<MemFun>::ClassType * obj, MemFun fun)
  {
    return utilspp::Functor<typename utilspp::PointerOnMemberFunction<MemFun>::ReturnType, 
      typename utilspp::PointerOnMemberFunction<MemFun>::ParamList>(obj, fun);
  }
}

#include "Binder.hpp"

#endif
