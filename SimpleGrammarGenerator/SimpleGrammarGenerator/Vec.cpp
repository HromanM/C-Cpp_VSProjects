#include "stdafx.h"
#include "Vec.h"

template<class T> Vec<T>::operator=(const Vec<T>& pso)
{
	if (&pso != this)
	{
		destroyVec();
		constructVec(pso.begin(), pso.end());
	}
	return *this;
}