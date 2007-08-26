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

#include "global.h"
#include "Form.hpp"


cURLpp::HttpPost::HttpPost()
  : mFirst(NULL)
  , mLast(NULL)
{}

cURLpp::HttpPost::~HttpPost()
{
  clear();
}


cURLpp::HttpPost &
cURLpp::HttpPost::operator=(const std::list< cURLpp::FormPart * > &posts)
{
  clear();

  cURLpp::FormPart *form;
  std::list< cURLpp::FormPart * >::const_iterator pos;
  for(pos = posts.begin(); pos != posts.end(); pos++) {
    form = (*pos)->clone();
    mForms.push_back(form);
    form->add(&mFirst, &mLast);
  } 
  
  return (*this);
}

::curl_httppost *
cURLpp::HttpPost::cHttpPost() const
{
  return mFirst;
}

void
cURLpp::HttpPost::clear()
{
  if(mFirst != NULL) {
    ::curl_formfree(mFirst);
    mFirst = NULL;
    mLast = NULL;
  }
  
  std::list< cURLpp::FormPart * >::const_iterator pos;
  for(pos = mForms.begin(); pos != mForms.end(); pos++) {
    delete (*pos);
  }
  mForms.clear();
}

std::list< cURLpp::FormPart *> cURLpp::HttpPost::getList()
{
  //I'm not sure cloning is absolutely necessary.
  std::list< cURLpp::FormPart * > newForm;

  cURLpp::FormPart *form;
  std::list< cURLpp::FormPart * >::const_iterator pos;
  for(pos = mForms.begin(); pos != mForms.end(); pos++) {
    form = (*pos)->clone();
    newForm.push_back(form);
//     form->add(&mFirst, &mLast);
  } 
  return newForm;
}

cURLpp::FormPart::FormPart(const char *name)
  : mName(name)
{}

cURLpp::FormPart::~FormPart()
{}

cURLpp::FormPart::FormPart(const std::string &name)
  : mName(name)
{}

cURLpp::FormParts::File::File(const char *name, const char *filename)
  : FormPart(name)
  , mFilename(filename)
{}

cURLpp::FormParts::File::~File()
{}

cURLpp::FormParts::File::File(const char *name, const char *filename, const char *contentType)
  : FormPart(name)
  , mFilename(filename)
  , mContentType(contentType)
{}

cURLpp::FormParts::File::File(const std::string &name, 
			      const std::string &filename)
  : FormPart(name)
  , mFilename(filename)
{}
  
cURLpp::FormParts::File::File(const std::string &name, 
			      const std::string &filename,
			      const std::string &contentType)
  : FormPart(name)
  , mFilename(filename)
  , mContentType(contentType)
{}

cURLpp::FormParts::File *
cURLpp::FormParts::File::clone() 
{
   return new cURLpp::FormParts::File(*this);
}

void
cURLpp::FormParts::File::add(::curl_httppost **first, 
			     ::curl_httppost **last)
{
  // One instance = One curl_httppost, so we don't
  // need to duplicate the memory.
  if(mContentType.empty()) {
    curl_formadd(first, 
		 last, 
		 CURLFORM_PTRNAME,
		 mName.c_str(), 
		 CURLFORM_FILE,
		 mFilename.c_str(),
		 CURLFORM_END );
  }
  else {
    curl_formadd(first, 
		 last, 
		 CURLFORM_PTRNAME, 
		 mName.c_str(), 
		 CURLFORM_FILE,
		 mFilename.c_str(),
		 CURLFORM_CONTENTTYPE,
		 mContentType.c_str(),
		 CURLFORM_END);
  }
}


cURLpp::FormParts::Content::Content(const char *name, 
				    const char *content)
  : FormPart(name)
  , mContent(content)
{}

cURLpp::FormParts::Content::~Content()
{}

cURLpp::FormParts::Content::Content(const char *name, 
				    const char *content, const char *contentType)
  : FormPart(name)
  , mContent(content)
  , mContentType(contentType)
{}

cURLpp::FormParts::Content::Content(const std::string &name, 
				    const std::string &content)
  : FormPart(name)
  , mContent(content)
{}

cURLpp::FormParts::Content::Content(const std::string &name, 
				    const std::string &content,
				    const std::string &contentType)
  : FormPart(name)
  , mContent(content)
  , mContentType(contentType)
{}

cURLpp::FormParts::Content *
cURLpp::FormParts::Content::clone() 
{
   return new cURLpp::FormParts::Content(*this);
}

void
cURLpp::FormParts::Content::add(::curl_httppost **first, 
				::curl_httppost **last)
{
  // We uses options that will copy internally the string (c_str),
  // so we don't need to worry about the memory.
  if(mContentType.empty()) {
    curl_formadd(first, 
		 last, 
		 CURLFORM_PTRNAME, 
		 mName.c_str(), 
		 CURLFORM_PTRCONTENTS,
		 mContent.c_str(),
		 CURLFORM_END);
  }
  else {
    curl_formadd(first, 
		 last, 
		 CURLFORM_PTRNAME, 
		 mName.c_str(), 
		 CURLFORM_PTRCONTENTS,
		 mContent.c_str(),
		 CURLFORM_CONTENTTYPE,
		 mContentType.c_str(),
		 CURLFORM_END );
  }
}
