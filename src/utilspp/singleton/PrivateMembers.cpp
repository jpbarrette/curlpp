#include <cstdlib>

#include "utilspp/singleton/PrivateMembers.hpp"

utilspp::PrivateMembers::TrackerArray
   utilspp::PrivateMembers::mTrackerArray = NULL;

int utilspp::PrivateMembers::mNbElements = 0;

utilspp::PrivateMembers::LifetimeTracker::LifetimeTracker( unsigned int
      longevity ) 
: 
mLongevity(longevity)
{}

utilspp::PrivateMembers::LifetimeTracker::~LifetimeTracker()
{}

bool
utilspp::PrivateMembers::LifetimeTracker::compare( 
      const LifetimeTracker * l, 
      const LifetimeTracker * r 
      )
{
   return l->mLongevity < r->mLongevity;
}

void
utilspp::PrivateMembers::atExitFunc()
{
   assert((mTrackerArray != NULL) && 
	  (mNbElements> 0));

   //Pick the element at the top of the stack.
   LifetimeTracker* top =  mTrackerArray[mNbElements - 1];

   //Remove that object off the stack.
   //Don't check errors-realloc with less memory, cause that can't fail.
   mTrackerArray = static_cast< 
     utilspp::PrivateMembers::TrackerArray>(std::realloc(mTrackerArray, 
							    --mNbElements));

   //Destroy the element.
   delete top;
}

