#include "curlpp/internal/SList.hpp"

#include <cassert>
#include <ostream>
#include <string>

namespace curlpp {

namespace internal {

SList::SList(const SList& rhs) : mList(nullptr) {
  constructFrom(rhs.mList);
}

SList::SList(std::unique_ptr<curl_slist> list) : mList(list.release()) {}

SList::SList(const std::list<std::string>& rhs) : mList(nullptr) {
  set(rhs);
}

SList::~SList() {
  clear();
}

void SList::clear() {
  if (mList != nullptr) {
    curl_slist_free_all(mList);
    mList = nullptr;
  }
}

void SList::constructFrom(curl_slist* list) {
  // mList needs to be null. This guarantees that we won't
  // stumble upon bugs like current given list is a portion
  // of owned list or vice versa, and we endup deleting a
  // portion of it.
  //
  // So, we'll be sure to create a new list.
  assert(!mList);

  curl_slist* c = list;
  while (c) {
    mList = curl_slist_append(mList, c->data);
    c = c->next;
  }
}

void SList::set(const std::list<std::string>& list) {
  clear();

  for (auto& elem : list) {
    mList = curl_slist_append(mList, elem.c_str());
  }
}

SList::operator std::list<std::string>() {
  return list();
}

SList& SList::operator=(const std::list<std::string>& list) {
  set(list);
  return (*this);
}

curl_slist* SList::cslist() const {
  return mList;
}

std::list<std::string> SList::list() {
  std::list<std::string> returnValue;
  curl_slist* c = mList;
  while (c) {
    returnValue.push_back(c->data);
    c = c->next;
  }

  return returnValue;
}

void SList::buildList(std::unique_ptr<curl_slist> list,
                      std::list<std::string>& value) {
  value.clear();

  SList slist(std::move(list));

  curl_slist* c = slist.mList;
  while (c) {
    value.push_back(c->data);
    c = c->next;
  }
}

}  // namespace internal

}  // namespace curlpp

std::ostream& operator<<(std::ostream& stream,
                         const std::list<std::string>& value) {
  for (std::list<std::string>::const_iterator pos = value.begin();
       pos != value.end(); pos++) {
    if (pos != value.begin()) {
      stream << ", ";
    }
    stream << (*pos);
  }

  return stream;
}
