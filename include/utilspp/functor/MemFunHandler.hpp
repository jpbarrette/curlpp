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

#ifndef UTILSPP_MEMFUNHANDLER_HPP
#define UTILSPP_MEMFUNHANDLER_HPP

namespace utilspp
{
  template <class ParentFunctor, typename PointerToObj, typename PointerToMemFn>
  class MemFunHandler : public FunctorImpl<typename ParentFunctor::ResultType,
					    typename ParentFunctor::ParmList>
  {
  public:
    typedef typename ParentFunctor::ResultType ResultType;
    MemFunHandler(PointerToObj obj, PointerToMemFn memFn) 
      : mObj(obj)
      , mMemFn(memFn)
    {}

    MemFunHandler* clone() const
    {return new MemFunHandler(*this);}
    
    ResultType operator()()
    {return ((*mObj).*mMemFn)();}

    ResultType operator()(typename ParentFunctor::Parm1 p1)
    {return ((*mObj).*mMemFn)(p1);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2)
    {return ((*mObj).*mMemFn)(p1, p2);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, 
			  typename ParentFunctor::Parm2 p2, 
			  typename ParentFunctor::Parm3 p3)
    {return ((*mObj).*mMemFn)(p1, p2, p3);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12, typename ParentFunctor::Parm13 p13)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12, typename ParentFunctor::Parm13 p13, typename ParentFunctor::Parm14 p14)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);}

    ResultType operator()(typename ParentFunctor::Parm1 p1, typename ParentFunctor::Parm2 p2, typename ParentFunctor::Parm3 p3, typename ParentFunctor::Parm4 p4, typename ParentFunctor::Parm5 p5, typename ParentFunctor::Parm6 p6, typename ParentFunctor::Parm7 p7, typename ParentFunctor::Parm8 p8, typename ParentFunctor::Parm9 p9, typename ParentFunctor::Parm10 p10, typename ParentFunctor::Parm11 p11, typename ParentFunctor::Parm12 p12, typename ParentFunctor::Parm13 p13, typename ParentFunctor::Parm14 p14, typename ParentFunctor::Parm15 p15)
    {return ((*mObj).*mMemFn)(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);}

  private:
    PointerToObj mObj;
    PointerToMemFn mMemFn;
  };
}

#endif

