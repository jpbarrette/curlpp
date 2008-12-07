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

#ifndef CURLPP_STREAM_TRAIT_HPP
#define CURLPP_STREAM_TRAIT_HPP

#include "buildconfig.h"
#include "StorageTrait.hpp"

namespace cURLpp
{

   /**
    * Class for Input 'stream' storage trait.
    */
   CURLPPAPI class IStreamTrait : public InputTrait
   {

      public:
         virtual ~IStreamTrait()
         {}

         IStreamTrait( std::istream* file ) : mFile( file )
         {}

         size_t read( void *buffer, size_t length );

      protected:
         std::istream* mFile;
   };

   // ============================================================================
   // Class for Output 'stream' storage trait.
   // ============================================================================
   CURLPPAPI class OStreamTrait : public OutputTrait
   {

      public:
         virtual ~OStreamTrait()
         {}

         OStreamTrait( std::ostream* file ) : mFile( file )
         {}

         size_t write( void *buffer, size_t length );

      protected:
         std::ostream* mFile;
   };

}

#endif // #ifndef CURLPP_STREAM_TRAIT_HPP

