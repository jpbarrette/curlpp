#include <string>
#include <list>

#include "global.h"
#include "Info.hpp"


template< >
void
cURLpp::InfoTypeConverter< std::string >::get(cURLpp::Easy &handle, 
				              CURLINFO info,
				              std::string &value)
{
  char *tmp;
  InfoGetter::get(handle, info, tmp);
  value = tmp;
}

template< >
void 
cURLpp::InfoTypeConverter< std::list< std::string > >::get(cURLpp::Easy &,
			                                   CURLINFO ,
						           std::list< std::string > &)
{
  
}
