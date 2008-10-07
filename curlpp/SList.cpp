#include "global.h"
#ifndef WIN32
#include "config.h"
#endif

#if HAVE_OSTREAM
#include <ostream>
#else
#include <ostream.h>
#endif

#include <string.h>
#include <string>

#include "global.h"
#include "SList.hpp"

cURLpp::SList::SList(const SList &rhs) 
  : mList( 0 )
  , mData(rhs.mData)
{
  update();
}

cURLpp::SList::SList(curl_slist *list)
  : mList(NULL)
{
  constructFrom(list);
}

cURLpp::SList::SList(const std::list< std::string > &rhs)
  : mList(0)
  , mData(rhs)
{
  update();
}

cURLpp::SList::SList() : mList( 0 )
{}

cURLpp::SList::~SList()
{
   clear();
}

void
cURLpp::SList::clear() {
   if( mList != 0 )
   {
      curl_slist_free_all( mList );
      mList = 0;
   }
}


void 
cURLpp::SList::constructFrom(curl_slist *list)
{
  mData.clear();

  curl_slist *c = list;
  while(c)
    {
      mData.push_back(c->data);
      c = c->next;
    }

  update();
}

void 
cURLpp::SList::set( const std::list< std::string > &list) 
{
  mData = list;
  update();
}


void 
cURLpp::SList::update() 
{
  clear();

  for(std::list< std::string >::const_iterator pos = mData.begin();
      pos != mData.end();
      pos++) {
    mList = curl_slist_append( mList, (*pos).c_str() );
  }
}


cURLpp::SList::operator std::list< std::string > ()
{
  return list();
}


cURLpp::SList &
cURLpp::SList::operator=( const std::list< std::string > &list )
{
  set(list);
  return (*this);
}

curl_slist *
cURLpp::SList::cslist() const
{
  return mList;
}

std::list< std::string >
cURLpp::SList::list() 
{
  return mData;
}


std::ostream &operator<<(std::ostream &stream, const std::list< std::string > &value)
{
  for(std::list< std::string >::const_iterator pos = value.begin();
      pos != value.end();
      pos++) {
    if(pos != value.begin()) {
      stream << ", ";
    }
    stream << (*pos);
  }

  return stream;
}
