#include <string>
#include <list>

#include "global.h"
#include "Info.hpp"
#include "SList.hpp"

namespace cURLpp {

template< >
void
InfoTypeConverter< std::string >::get(cURLpp::Easy &handle, 
				      CURLINFO info,
				      std::string &value)
{
  char *tmp;
  InfoGetter::get(handle, info, tmp);
  value = tmp;
}

template< >
void 
cURLpp::InfoTypeConverter< std::list< std::string > >::get(cURLpp::Easy & handle,
			                                   CURLINFO info,
						           std::list< std::string > &value)
{ 
  curl_slist * tmpList = NULL;
  InfoGetter::get(handle, info, tmpList);
  SList slist(tmpList);
  value = slist.list();
}

template< >
void
InfoTypeConverter< long >::get(cURLpp::Easy &handle, 
			       CURLINFO info,
			       long &value)
{
  InfoGetter::get(handle, info, value);
}

template< >
void
InfoTypeConverter< double >::get(cURLpp::Easy &handle, 
				 CURLINFO info,
				 double &value)
{
  curl_off_t tmp;
  InfoGetter::get(handle, info, tmp);
  value = (double)tmp;
}

}

