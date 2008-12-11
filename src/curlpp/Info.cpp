#include <string>
#include <list>

#include "curlpp/global.h"
#include "curlpp/Info.hpp"
#include "curlpp/SList.hpp"

namespace curlpp 
{

template<>
void
InfoTypeConverter<std::string>::get(curlpp::Easy & handle, 
				      CURLINFO info,
				      std::string & value)
{
  char * tmp;
  InfoGetter::get(handle, info, tmp);
  value = tmp;
}

template<>
void 
InfoTypeConverter<std::list<std::string> >::get(curlpp::Easy & handle,
						   CURLINFO info,
						   std::list<std::string> & value)
{ 
  curl_slist * tmpList = NULL;
  InfoGetter::get(handle, info, tmpList);
  SList slist(tmpList);
  value = slist.list();
}

template<>
void
InfoTypeConverter<long>::get(curlpp::Easy & handle, 
			       CURLINFO info,
			       long & value)
{
  InfoGetter::get(handle, info, value);
}

template<>
void
InfoTypeConverter<double>::get(curlpp::Easy & handle, 
				 CURLINFO info,
				 double & value)
{
  curl_off_t tmp;
  InfoGetter::get(handle, info, tmp);
  value = (double)tmp;
}

}
