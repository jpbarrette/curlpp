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

#ifndef UTILSPP_FUNCTORIMPL_HPP
#define UTILSPP_FUNCTORIMPL_HPP

namespace utilspp
{
  template<typename R, class TList>
  struct FunctorImpl;
  
  template<typename R>
  struct FunctorImpl<R, utilspp::NullType >
  {
    R operator()() = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };
  
  template<typename R, typename P1>
  struct FunctorImpl<R, TYPE_LIST_1(P1)>
  {
    virtual R operator()(P1) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };
  
  template<typename R, typename P1, typename P2>
  struct FunctorImpl<R, TYPE_LIST_2(P1, P2)>
  {
    virtual R operator()(P1, P2) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };
  
  template<typename R, typename P1, typename P2, typename P3>
  struct FunctorImpl<R, TYPE_LIST_3(P1, P2, P3)>
  {
    virtual R operator()(P1, P2, P3) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4>
  struct FunctorImpl<R, TYPE_LIST_4(P1, P2, P3, P4)>
  {
    virtual R operator()(P1, P2, P3, P4) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
  struct FunctorImpl<R, TYPE_LIST_5(P1, P2, P3, P4, P5)>
  {
    virtual R operator()(P1, P2, P3, P4, P5) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template< 
    typename R, 
    typename P1, 
    typename P2, 
    typename P3, 
    typename P4, 
    typename P5, 
    typename P6>
  struct FunctorImpl<R, TYPE_LIST_6(P1, P2, P3, P4, P5, P6)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template< 
    typename R, 
    typename P1, 
    typename P2, 
    typename P3, 
    typename P4, 
    typename P5, 
    typename P6, 
    typename P7>
  struct FunctorImpl<R, TYPE_LIST_7(P1, P2, P3, P4, P5, P6, P7)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template< 
    typename R, 
    typename P1, 
    typename P2, 
    typename P3, 
    typename P4, 
    typename P5, 
    typename P6, 
    typename P7, 
    typename P8>
  struct FunctorImpl<R, TYPE_LIST_8(P1, P2, P3, P4, P5, P6, P7, P8)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template< 
    typename R, 
    typename P1, 
    typename P2, 
    typename P3, 
    typename P4, 
    typename P5, 
    typename P6, 
    typename P7, 
    typename P8, 
    typename P9>
  struct FunctorImpl<R, TYPE_LIST_9(P1, P2, P3, P4, P5, P6, P7, P8, P9)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template< 
    typename R, 
    typename P1, 
    typename P2, 
    typename P3, 
    typename P4, 
    typename P5, 
    typename P6, 
    typename P7, 
    typename P8, 
    typename P9, 
    typename P10>
  struct FunctorImpl<R, TYPE_LIST_10(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11>
  struct FunctorImpl<R, TYPE_LIST_11(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12>
  struct FunctorImpl<R, TYPE_LIST_12(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13>
  struct FunctorImpl<R, TYPE_LIST_13(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14>
  struct FunctorImpl<R, TYPE_LIST_14(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };

  template<typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9, typename P10, typename P11, typename P12, typename P13, typename P14, typename P15>
  struct FunctorImpl<R, TYPE_LIST_15(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15)>
  {
    virtual R operator()(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) = 0;
    virtual FunctorImpl * clone() const = 0;
    virtual ~FunctorImpl(){};
  };
}

#endif
