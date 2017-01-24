#include "stdafx.h"
#include "ServiceClass.h"
#include <stdexcept>

using std::runtime_error;

template <class T>
ServiceClass<T>& ServiceClass<T>::operator=(const ServiceClass& s)
{
	if (&s != this)
	{
		delete ptr;
		ptr = s.ptr ? s.ptr->cloneSt() : 0;
	}
	return *this;
}

template <class T>
 T& ServiceClass<T>::operator*() const
{
	if (ptr)
		return *ptr;
	throw runtime_error("non valid ServiceClass pointer");
}

 template <class T>
 T* ServiceClass<T>::operator->() const
 {
	 if (ptr)
		 return ptr;
	 throw runtime_error("non valid ServiceSlass pointer");
 }

 /*template <class T> 
 RefService<T>& RefService<T>::operator=(const RefService& pso)
 {
	 ++*pso.refPtr;
	 return *this;
 }*/