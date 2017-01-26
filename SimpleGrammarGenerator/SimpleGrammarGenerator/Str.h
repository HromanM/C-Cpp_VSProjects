#pragma once
#include "Vec.h"
#include <iterator>
#include "Ptr.h"
#include "Ptr.cpp"

class Str {
public:
	typedef Vec<char>::size_type size_type;

	// constructors
	Str(): data(new Vec<char>) {}
	Str(size_type n, char c): data(new Vec<char>(n, c)) {}
	Str(const char* cp) : data(new Vec<char>)
	{
		std::copy(cp, cp + std::strlen(cp), std::back_inserter(*data));
	}
	template<class T> Str(T b, T e): data(new Vec<char>)
	{
		std::copy(b, e, std::back_inserter(*data));
	}

	// operators
	char& operator[](size_type n) { 
		data.createUniq();
		return (*data)[n]; 
	}
	const char& operator[](size_type n) const { return (*data)[n]; }
	friend std::istream& operator>>(std::istream&, Str&);
	friend std::istream& getline (std::istream&, Str&);
	Str& operator+=(const Str&);

	// interface
	size_type size() const { return data->size(); }
	typedef char* iterator;
	typedef const char* const_iterator;
	iterator begin() { return data->begin(); }
	const_iterator begin() const { return data->begin(); }
	iterator end() { return data->end(); }
	const_iterator end() const { return data->end(); }

private:
	Ptr<Vec<char> > data;
};

std::istream& operator>> (std::istream&, Str&);
std::ostream& operator<< (std::ostream&, const Str&);

template<> Vec<char>* clone(const Vec<char>* vp)
{
	return new Vec<char>(*vp);
}