/*
 *    Copyright (c) <2002-2006> <Jean-Philippe Barrette-LaPierre>
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

#ifndef CURLPP_STORAGE_HPP
#define CURLPP_STORAGE_HPP


#include "curlpp/buildconfig.h"

namespace curlpp
{
  /**
   * This is the base class used to manage the writing of the ouput, headers, 
   * input, etc.
   */
  template< typename FuncType, typename TraitType >
  CURLPPAPI class StorageBase
  {
  public:
    virtual void stream(TraitType *trait) = 0;
    virtual void func(FuncType func) = 0;

  public:
    typedef TraitType StorageTraitType;
  };


   /**
    * This class manage the writing of the body ouput of the "easy" parent.
    * By default this class is using the "stdoutTrait" trait.
    */
  template< typename TraitType >
  CURLPPAPI class WriteStorage : public StorageBase< curlpp::curl_write_callback, TraitType >
  {
  public:
    WriteStorage(TraitType *trait, curlpp::curl_write_callback func);
    virtual void stream(TraitType *trait);
    virtual void func(curlpp::curl_write_callback func);

  private:
    static size_t writeCallback(void *buffer,
				size_t size,
				size_t nitems,
				void *outstream);
  };


   /**
    * This class manage the writing of the header ouput of the "easy" parent.
    * By default this class is using the "stdoutTrait" trait.
    */
   CURLPPAPI class HeaderStorage : public StorageBase< OutputTrait >
   {
      public:
         HeaderStorage(
               curl *parent,
               OutputTrait *trait = &stdoutTrait,
               bool own = false
               ) : StorageBase< OutputTrait >( parent, trait, &stdoutTrait, own )
               {}

         void setCallback();
         void setCallbackData();

      private:
         static size_t writeCallback(
               void *buffer,
               size_t size,
               size_t nitems,
               void *outstream
               );
   };

   /**
    * This class manage the reading of the "easy" parent. 
    * By default this class is using the "stdinTrait" trait.
    */
   CURLPPAPI class InputStorage : public StorageBase< InputTrait >
   {
      public:
         InputStorage(
               curl *parent,
               InputTrait *trait = &stdinTrait,
               bool own = false
               ) : StorageBase< InputTrait >( parent, trait, &stdinTrait, own )
               {}

         void setCallback();
         void setCallbackData();

      private:
         static size_t readCallback(
               void *buffer,
               size_t size,
               size_t nmemb,
               void *instream
               );
   };

   /**
    * This class manage the writing of the progess ouput of the "easy" parent. 
    * By default this class is using the "defaultProgressTrait" trait.
    */
   CURLPPAPI class ProgressStorage : public StorageBase< ProgressTrait >
   {
      public:
         ProgressStorage(
               curl *parent,
               ProgressTrait *trait = &defaultProgressTrait,
               bool own = false
               ) : StorageBase< ProgressTrait >( parent, trait, &defaultProgressTrait, own )
               {}

         void setCallback();
         void setCallbackData();

      private:
         static int progressCallback(
               void *clientp,
               double dltotal,
               double dlnow,
               double ultotal,
               double ulnow
               );
   };

   /**
    * This class manage the input of passwords for the "easy" parent. 
    * By default this class is using the "defaultPasswdTrait" trait.
    */
   CURLPPAPI class PasswdStorage : public StorageBase< PasswdTrait >
   {
      public:
         PasswdStorage(
               curl *parent,
               PasswdTrait *trait = &defaultPasswdTrait,
               bool own = false
               ) : StorageBase< PasswdTrait >( parent, trait, &defaultPasswdTrait, own )
               {}

         void setCallback();
         void setCallbackData();

      private:
         static int passwd_callback(
               void *client,
               char *prompt,
               char *buffer,
               int buflen
               );
   };

   /**
    * This class manage the writing of the debug ouput of the "easy" parent. 
    * By default this class is using the "defaultDebugTrait" trait.
    */
   CURLPPAPI class DebugStorage : public StorageBase< DebugTrait >
   {
      public:
         DebugStorage(
               curl *parent,
               DebugTrait *trait = &defaultDebugTrait,
               bool own = false
               ) : StorageBase< DebugTrait >( parent, trait, &defaultDebugTrait, own )
               {}

         void setCallback();
         void setCallbackData();

      private:
         static int debug_callback(
               CURL *handle,
               curlpp::debug::Type info,
               char *buffer,
               size_t len,
               void *ptr
               );
   };

   /**
    * This class manage Storage classes, who derives from StorageBase. 
    * This class calls setCallback() and setCallbackData() when it's
    * needed by the Storage.
    */
   template < class StorageType >
      CURLPPAPI class Storage
      {
         public:
            Storage( curl *parent );
            void trait( typename StorageType::StorageTraitType *giventTrait, bool own = false );

         private:
            StorageType mStorage;
      };

   template < class StorageType >
      Storage< StorageType >::Storage( curl *parent ) : mStorage( parent )
      {
         mStorage.setCallback();
         mStorage.setCallbackData();
      }

   template < class StorageType >
      void Storage< StorageType >::trait( typename StorageType::StorageTraitType *giventTrait, bool own ) {
         mStorage.trait( giventTrait, own );
         mStorage.setCallbackData();
      }

#if LIBCURL_VERSION_NUM >= 0x070b01
   template <>
      CURLPPAPI class Storage< PasswdStorage >
      {
         public:
            Storage( curl *parent );
            void trait( PasswdTrait *giventTrait, bool own = false );
      };
#endif

} // namespace curlpp

namespace cURLpp = curlpp;

#endif
