#include "curlpp/internal/SList.hpp"

#include "curlpp/Info.hpp"

#include <list>
#include <memory>
#include <string>

namespace curlpp {

template <>
void InfoTypeConverter<std::string>::get(const curlpp::Easy& handle,
                                         CURLINFO info,
                                         std::string& value) {
  char * tmp = NULL;
  InfoGetter::get(handle, info, tmp);
  if (tmp == NULL)
    value.clear();
  else
    value = tmp;
}

template <>
void InfoTypeConverter<std::list<std::string> >::get(
    const curlpp::Easy& handle,
    CURLINFO info,
    std::list<std::string>& value) {
  curl_slist* tmpList = NULL;
  InfoGetter::get(handle, info, tmpList);

  internal::SList::buildList(std::unique_ptr<curl_slist>(tmpList), value);
}

template <>
void InfoTypeConverter<long>::get(const curlpp::Easy& handle,
                                  CURLINFO info,
                                  long& value) {
  InfoGetter::get(handle, info, value);
}

template <>
void InfoTypeConverter<double>::get(const curlpp::Easy& handle,
                                    CURLINFO info,
                                    double& value) {
  curl_off_t tmp;
  InfoGetter::get(handle, info, tmp);
  value = reinterpret_cast<double&>(tmp);
}

}  // namespace curlpp
