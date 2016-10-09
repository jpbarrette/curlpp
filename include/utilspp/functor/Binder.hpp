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

#ifndef CURLPP_BINDER_HPP
#define CURLPP_BINDER_HPP

#include <memory>

namespace utilspp
{
  template<typename Incoming>
  class BinderFirst : public FunctorImpl<typename Incoming::ResultType,
					  typename Incoming::ParmList::tail>
  {
    typedef utilspp::Functor<typename Incoming::ResultType, typename Incoming::ParmList::tail> Outgoing;
    typedef typename Incoming::Parm1 Bound;
    typedef typename Incoming::ResultType ResultType;
    
  public:
    BinderFirst(const Incoming & fun, Bound bound)
      : mFun(fun), mBound(bound)
    {}

    BinderFirst* clone() const
    {return new BinderFirst(*this);}

    ResultType operator()()
    {return mFun(mBound)();}

    ResultType operator()(typename Outgoing::Parm1 p1)
    {return mFun(mBound, p1);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2)
    {return mFun(mBound, p1, p2);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3)
    {return mFun(mBound, p1, p2, p3);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4)
    {return mFun(mBound, p1, p2, p3, p4);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5)
    {return mFun(mBound, p1, p2, p3, p4, p5);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8, p9);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11, typename Outgoing::Parm12 p12)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11, typename Outgoing::Parm12 p12, typename Outgoing::Parm13 p13)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);}

    ResultType operator()(typename Outgoing::Parm1 p1, typename Outgoing::Parm2 p2, typename Outgoing::Parm3 p3, typename Outgoing::Parm4 p4, typename Outgoing::Parm5 p5, typename Outgoing::Parm6 p6, typename Outgoing::Parm7 p7, typename Outgoing::Parm8 p8, typename Outgoing::Parm9 p9, typename Outgoing::Parm10 p10, typename Outgoing::Parm11 p11, typename Outgoing::Parm12 p12, typename Outgoing::Parm13 p13, typename Outgoing::Parm14 p14)
    {return mFun(mBound, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);}

  private:
    Incoming mFun;
    Bound mBound;
  };
  
  template<typename R, class TList>
  Functor<R, typename TList::tail> BindFirst(const Functor<R, TList> & fun,
					     typename TList::head bound)
  {
    typedef Functor<R, TList> Incoming;
    typedef Functor<R, typename TList::tail> Outgoing;
    
    std::unique_ptr<typename Outgoing::Impl> impl_ptr(new BinderFirst<Incoming>(fun, bound));
    return Outgoing(std::move(impl_ptr));
  }
    
}

#endif
