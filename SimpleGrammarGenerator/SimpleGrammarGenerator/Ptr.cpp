#include "stdafx.h"
#include"Ptr.h"
#include <stdexcept>

using std::runtime_error;

template <class T> Ptr<T>& Ptr<T>::operator=(const Ptr& pso)
{
	++*pso.refPtr;
	if (--*refPtr == 0)
	{
		delete refPtr;
		delete ptr;
	}
	refPtr = pso.refPtr;
	p = pso.ptr;
	return *this;
}

template <class T> Ptr<T>::~Ptr()
{
	if (--*refPtr == 0)
	{
		delete refPtr;
		delete ptr;
	}
}

template <class T> T& Ptr<T>::operator*() const
{
	if (ptr)
		return *ptr;
	throw runtime_error("uninitialized Ptr.");
}

template <class T> T* Ptr<T>::operator->() const
{
	if (ptr)
		return ptr;
	throw runtime_error("uninitialized Ptr.");
}

