
template<typename T>
void
utilspp::PrivateMembers::Deleter<T>::deleteObject(T * obj)
{
   delete obj;
}

template<typename T, typename TDestroyer>
utilspp::PrivateMembers::ConcreteLifetimeTracker<T, TDestroyer>::ConcreteLifetimeTracker( 
      T * obj, unsigned int longevity, TDestroyer d) 
: LifetimeTracker(longevity)
, mTracked(obj)
, mDestroyer(d)
{}

template<typename T, typename TDestroyer>
utilspp::PrivateMembers::ConcreteLifetimeTracker<T, TDestroyer>::~ConcreteLifetimeTracker()
{
   mDestroyer(mTracked);
}


template <typename T>
void
utilspp::PrivateMembers::adapter<T>::operator()(T*) 
{ 
   return (*mFunc)(); 
}

