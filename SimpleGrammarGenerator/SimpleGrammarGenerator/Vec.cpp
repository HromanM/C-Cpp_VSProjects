#include "stdafx.h"
#include "Vec.h"
#include <memory>

template<class T> Vec<T>& Vec<T>::operator=(const Vec& pso)
{
	if (&pso != this)
	{
		destroyVec();
		constructVec(pso.begin(), pso.end());
	}
	return *this;
}

template<class T> void Vec<T>::constructVec()
{
	data = avail = limit = 0;
}

template<class T> void Vec<T>::constructVec(size_type n, const T& t)
{
	data = alloc.allocate(n);
	limit = volny = data + n;
	std::uninitialized_fill(data, volny, t);
}

template<class T> void Vec<T>::constructVec(const_iterator b, const_iterator e)
{
	data = alloc.allocate(e - b);
	limit = volny = std::uninitialized_copy(b, e, data);
}

template<class T> void Vec<T>::destroyVec()
{
	if (data)
	{
		iterator it = volny;
		while (it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;
}

template<class T> void Vec<T>::spreadVecDataSpace()
{
	size_type newSize = (limit - data) * 2;

	iterator newData = alloc.allocate(newSize);
	iterator newAvail = std::uninitialized_copy(data, avail, newData);
	
	destroyVec();

	data = newData;
	avail = newAvail;
	limit = data + newSize;
}

template<class T> void Vec<T>::uncontrolledAdd(const T& t)
{
	alloc.construct(avail++, t);
}