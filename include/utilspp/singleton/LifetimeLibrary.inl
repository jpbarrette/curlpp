template<typename T, typename TDestroyer>
void
utilspp::setLibraryLongevity(T * obj, unsigned int longevity, TDestroyer d)
{
   using namespace utilspp::PrivateMembers;
   
   LifetimeTracker * p = new ConcreteLifetimeTracker<T, TDestroyer>( 
         obj, longevity, d);

   utilspp::LifetimeLibrarySingleton::instance().add(p);
};

template<typename T>
void 
utilspp::LifetimeLibrary<T>::scheduleDestruction(T *obj, void (* func)())
{
   utilspp::PrivateMembers::adapter<T> adapter = { func };
   utilspp::setLibraryLongevity(obj, getLongevity( obj ), adapter);
}

template<typename T>
void 
utilspp::LifetimeLibrary<T>::onDeadReference()
{
   throw std::logic_error("Dead reference detected");
}

template<typename T>
utilspp::LifetimeLibraryGuard<T>::~LifetimeLibraryGuard()
{
  T::instance().terminate();
}

