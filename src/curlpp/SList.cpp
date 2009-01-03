#include "curlpp/global.h"

#if HAVE_OSTREAM
#  include <ostream>
#else
#  include <ostream.h>
#endif

#include <string>

#include "curlpp/SList.hpp"


curlpp::SList::SList(const SList & rhs) 
	: mList(0)
	, mData(rhs.mData)
{
	update();
}


curlpp::SList::SList(curl_slist * list)
	: mList(NULL)
{
	constructFrom(list);
}


curlpp::SList::SList(const std::list<std::string> & rhs)
	: mList(0)
	, mData(rhs)
{
	update();
}


curlpp::SList::SList() 
	: mList(0)
{}


curlpp::SList::~SList()
{
	clear();
}


void
curlpp::SList::clear()
{
	if(mList != 0)
	{
		curl_slist_free_all(mList);
		mList = 0;
	}
}


void 
curlpp::SList::constructFrom(curl_slist * list)
{
	mData.clear();

	curl_slist * c = list;
	while(c)
	{
		mData.push_back(c->data);
		c = c->next;
	}

	update();
}


void 
curlpp::SList::set(const std::list<std::string> & list) 
{
	mData = list;
	update();
}


void 
curlpp::SList::update() 
{
	clear();

	for(std::list<std::string>::const_iterator pos = mData.begin();
			pos != mData.end();
			pos++)
	{
		mList = curl_slist_append(mList, (*pos).c_str());
	}
}


curlpp::SList::operator std::list<std::string> ()
{
	return list();
}


curlpp::SList &
curlpp::SList::operator=(const std::list<std::string> & list)
{
	set(list);
	return (*this);
}


curl_slist *
curlpp::SList::cslist() const
{
	return mList;
}


std::list<std::string>
curlpp::SList::list() 
{
	return mData;
}


std::ostream & operator<<(std::ostream & stream, const std::list<std::string> & value)
{
	for(std::list<std::string>::const_iterator pos = value.begin();
			pos != value.end();
			pos++)
	{
		if(pos != value.begin())
		{
			stream << ", ";
		}
		stream << (*pos);
	}

	return stream;
}
