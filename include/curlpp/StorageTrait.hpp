/*
 *    Copyright (c) <2002-2008> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_STORAGE_TRAIT_HPP
#define CURLPP_STORAGE_TRAIT_HPP

#include "buildconfig.h"
#include "types.hpp"


/**
 * This is the virtual class that has to be used as the base class to specify
 * any kind of Storage trait. Subclasses need to implement the 'setup' method.
 * Storage traits can be used for input (read) or output (write).
 */
namespace curlpp
{

   CURLPPAPI class StorageTrait
   {
      public:
         StorageTrait( )
         {}

         virtual ~StorageTrait()
         {}

   };

   CURLPPAPI class InputTrait : public StorageTrait
   {
      public:
         InputTrait( )
         {}

         virtual ~InputTrait()
         {}

         virtual size_t read(void * buffer, size_t length) = 0;

   };

   CURLPPAPI class OutputTrait : public StorageTrait
   {
      public:
         OutputTrait( )
         {}

         virtual ~OutputTrait()
         {}

         virtual size_t write(void * buffer, size_t length) = 0;
   };

   CURLPPAPI class IOTrait : public InputTrait, public OutputTrait
   {
      public:
         IOTrait( )
         {}

         virtual ~IOTrait()
         {}
   }
   ;

   CURLPPAPI class ProgressTrait : public StorageTrait
   {
      public:
         ProgressTrait()
         {}

         virtual ~ProgressTrait()
         {}

         virtual bool ProgressFunction(
               double dltotal,
               double dlnow,
               double ultotal,
               double ulnow
               ) = 0;
   };

   CURLPPAPI class OutputProgressTrait : public ProgressTrait
   {
      public:
         OutputProgressTrait()
         {}

         virtual ~OutputProgressTrait()
         {}

         bool ProgressFunction(
               double dltotal,
               double dlnow,
               double ultotal,
               double ulnow
               );

   };

   static OutputProgressTrait defaultProgressTrait;

   /**
    * This class is the class you need to derive from to 
    * obtain a "home made" passwd callback, in order to 
    * manage by yourself the input of passwords.
    *
    * NOTE:to see how to use this check the 
    * defaultPasswdTrait, that's an 
    * InputPasswdTrait
    */
   CURLPPAPI class PasswdTrait : public StorageTrait
   {
      public:
         virtual ~PasswdTrait()
         {}

         virtual bool passwdFunction(
               char * prompt,
               char * buffer,
               int buflen
               ) = 0;
   };

   /**
    * This class is the default trait for 
    * PasswdStorage
    */
   CURLPPAPI class InputPasswdTrait : public PasswdTrait
   {
      public:
         virtual ~InputPasswdTrait()
         {}

         virtual bool passwdFunction(
               char * prompt,
               char * buffer,
               int buflen
               );
   };

   static InputPasswdTrait defaultPasswdTrait;

   /**
    * This class is the class you need to derive from to 
    * obtain a "home made" debug callback, in order to 
    * manage by yourself the output of debug.
    *
    * NOTE:to see how to use this check the 
    * defaultDebugTrait, that's an 
    * OutputDebugTrait
    */

   CURLPPAPI class DebugTrait : public StorageTrait
   {
      public:
         virtual ~DebugTrait()
         {}

         /**
          * You need to implement this function in order
          * to provide a "home made" debug function.
          *
          * NOTE:always use the buflen when using this data, 
          * buffer is treated at this point like binary data,
          * so it will NOT necesserily be NULL terminated.
          */
         virtual void debugFunction(
               curlpp::debug::Type type,
               char * buffer,
               int buflen
               ) = 0;
   };

   /**
    * This class is the default trait for the
    * DebugStorage class
    */
   CURLPPAPI class OutputDebugTrait : public DebugTrait
   {
      public:
         virtual ~OutputDebugTrait()
         {}

         virtual void debugFunction(
               curlpp::debug::Type type,
               char * buffer,
               int buflen
               );
   };

   static OutputDebugTrait defaultDebugTrait;

} // namespace curlpp

namespace cURLpp = curlpp;

#endif // #ifndef CURLPP_STORAGE_TRAIT_HPP
