#pragma once
#include "Vec.h"
#include <iterator>

class Str {
public:
	typedef Vec<char>::size_type size_type;

	// constructors
	Str() {}
	Str(size_type n, char c): data(n,c){}
	Str(const char* cp)
	{
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
	}
	template<class T> Str(T b, T e)
	{
		std::copy(b, e, std::back_inserter(data));
	}

	// operators
	char& operator[](size_type n) { return data[n]; }
	const char& operator[](size_type n) const { return data[n]; }
	friend std::istream& operator>>(std::istream&, Str&);
	Str& operator+=(const Str&);

	// interface
	size_type size() const { return data.size(); }

private:
	Vec<char> data;
};

std::istream& operator>> (std::istream&, Str&);
std::ostream& operator<< (std::ostream&, const Str&);