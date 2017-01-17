#pragma once

template <class T> class Vec {
public:
	// constructors
	Vec() { construct(); }
	explicit Vec(std::size_t n, const T& val = T()) { constructVec(n, val); }
	Vec(const Vec& v) { constructVec(v.begin(), v.end()); }
	~Vec() { destroyVec(); }

	//interface
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }
	Vec& operator=(const& Vec);
	iterator begin() { return data; }
	const_iterator beging() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	//functions
	size_type size() const { return avail - data; }
	void clear() { destroyVec(); }
	bool empty() const { return data == volny; }
	void push_back(const T t&)
	{
		if (avail == limit)
			spreadVecDataSpace();
		uncontrolledAdd(t);
	}

	// types def
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef  T& reference;
	typedef const T& const_reference;

private:
	iterator data;		// pointer to first data element
	iterator limit;		// pointer behind the last data element
	iterator avail;		// pointer behind the last valid data element

	// alocator
	std::allocator<t> alloc;

	// private fc
	void constructVec();
	void constructVec(size_type, const T&);
	void constructVec(const_iterator, const_iterator);
	void destroyVec();
	void spreadVecDataSpace();
	void uncontrolledAdd(const T&);
};
