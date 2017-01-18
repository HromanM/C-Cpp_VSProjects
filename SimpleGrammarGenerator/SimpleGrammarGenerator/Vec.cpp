#include "stdafx.h"
#include "Vec.h"
#include <memory>
#include <stdexcept>

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
/*
template<class T> void Vec<T>::pop_back()
{
	if ((data != avail) && data)
	{
		iterator it = --avail;
		alloc.destroy(it);
		--avail;
	}
}
*/
/*template<class T> void Vec<T>::clear()
{
	iterator it = avail;
	while ((it != data) && data)
	{
		alloc.destroy(--it);
	}
	avail = data;
}
*/
/*template<class T> iterator Vec<T>::erase(iterator it)
{
	if (it >= data && it < avail)
	{
		iterator iter = it;
		alloc.destroy(iter);
		iterator newAvail = std::uninitialized_copy(it+1, avail, it);
		alloc.destroy(--avail);
		return it;
	}
	else if (avail == data)
	{
		throw std::invalid_argument("erase Vec parameter out of range");
	}
	else
		throw std::invalid_argument("erase Vec - empty Vec");
}

template<class T> iterator Vec<T>::erase(iterator b, iterator e)
{
	if (b >= data && b < avail)
	{
		iterator it = b;
		while (it != e && it != avail)
		{
			alloc.destroy(++it);
		}
		iterator newAvail = std::uninitialized_copy(it, avail, b);
		while (avail != newAvail)
			alloc.destroy(--avail);
		return b;
	}
	else if (avail == data)
	{
		throw std::invalid_argument("erase Vec parameter out of range");
	}
	else
		throw std::invalid_argument("erase Vec - empty Vec");
}*/