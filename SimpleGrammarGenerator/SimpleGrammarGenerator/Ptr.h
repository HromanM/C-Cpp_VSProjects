#pragma once

template <class T> class Ptr {
public:
	void createUniq()
	{
		if (*refPtr != 1)
		{
			--*refPtr;
			refPtr = new size_t(1);
			ptr = ptr ? clone(ptr) : 0;
		}
	}

	Ptr() : refPtr(new size_t(1), ptr(0)) {}
	Ptr(T* t): refPtr(new size_t(1)), ptr(t) {}
	Ptr(const Ptr& o) : refPtr(o.refPtr), ptr(o.ptr) { ++*refPtr; }

	Ptr& operator=(const Ptr&);
	~Ptr();
	operator bool() const { return p; }
	T& operator*() const;
	T* operator->() const;
private:
	T* ptr;
	std::size_t* refPtr;
};

template <class T> T* clone(const T* tp)
{
	return tp->clone();
}
