#include <algorithm>

template<typename T, typename TDestroyer>
void
utilspp::setLongevity(T * obj, unsigned int longevity, TDestroyer d)
{
   using namespace utilspp::PrivateMembers;

   TrackerArray newArray = static_cast<TrackerArray>( 
         std::realloc(mTrackerArray, mNbElements + 1));
   if(newArray == NULL)
   {
      throw std::bad_alloc();
   }

   LifetimeTracker * p = 
	new ConcreteLifetimeTracker<T, TDestroyer>(obj, longevity, d);

   mTrackerArray = newArray;

   TrackerArray pos = std::upper_bound( 
         mTrackerArray, 
         mTrackerArray + mNbElements,
         p,
         &LifetimeTracker::compare);
   std::copy_backward( 
         pos, 
         mTrackerArray + mNbElements, 
         mTrackerArray + mNbElements + 1);

   *pos = p;
   mNbElements++;
   std::atexit(&atExitFunc);
};

template<typename T>
void 
utilspp::LifetimeWithLongevity<T>::scheduleDestruction(T * obj, void (* func)())
{
   utilspp::PrivateMembers::adapter<T> adapter = { func };
   utilspp::setLongevity(obj, getLongevity( obj ), adapter);
}

template<typename T>
void 
utilspp::LifetimeWithLongevity<T>::onDeadReference()
{
   throw std::logic_error("Dead reference detected");
}

template<typename T>
unsigned int 
utilspp::getLongevity(T *)
{
   return 1000;
}


