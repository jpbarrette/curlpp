#include "utilspp/singleton/SingletonHolder.hpp"
#include "utilspp/singleton/LifetimeLibrary.hpp"

utilspp::LifetimeLibraryImpl::LifetimeLibraryImpl()
   :
   mTrackerArray(NULL),
   mNbElements(0)
{}

utilspp::LifetimeLibraryImpl::~LifetimeLibraryImpl()
{
   terminate();
}

void
utilspp::LifetimeLibraryImpl::add(utilspp::PrivateMembers::LifetimeTracker * tracker)
{
   utilspp::PrivateMembers::TrackerArray newArray = static_cast<
      utilspp::PrivateMembers::TrackerArray>(std::realloc(mTrackerArray, 
							    mNbElements + 1));
   if(newArray == NULL)
   {
      throw std::bad_alloc();
   }

   mTrackerArray = newArray;

   utilspp::PrivateMembers::TrackerArray pos = 
     std::upper_bound(mTrackerArray, 
		      mTrackerArray + mNbElements,
		      tracker,
		      &utilspp::PrivateMembers::LifetimeTracker::compare);
   std::copy_backward(pos, 
		      mTrackerArray + mNbElements, 
		      mTrackerArray + mNbElements + 1);
   
   *pos = tracker;
   mNbElements++;
};

void
utilspp::LifetimeLibraryImpl::terminate()
{
  //The number of elements MUST always be equal or over zero.
  assert(mNbElements >= 0);
  
  while(mNbElements > 0)
  {
    //At this point the mTrackerArray MUST not be NULL.
    assert(mTrackerArray != NULL);
    
    //Pick the element at the top of the stack.
    utilspp::PrivateMembers::LifetimeTracker* top =  
      mTrackerArray[mNbElements - 1];
    
    //Remove that object off the stack.
    //Don't check errors-realloc with less memory, cause that can't fail.
    mTrackerArray = 
      static_cast<utilspp::PrivateMembers::TrackerArray>
      (std::realloc(mTrackerArray, --mNbElements));
    
    //Destroy the element.
    delete top;
  }
}

unsigned int 
utilspp::getLongevity(utilspp::LifetimeLibraryImpl *)
{
   return 0;
}

