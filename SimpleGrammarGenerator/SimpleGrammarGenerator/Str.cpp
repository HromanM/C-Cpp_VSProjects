#include "stdafx.h"
#include "Str.h"
#include <iostream>
#include "Vec.h"
#include "Vec.cpp"

using std::istream;
using std::ostream;

ostream& operator<<(ostream& os, const Str& str)
{
	for (Str::size_type i = 0; i <= str.size(); ++i)
		os << str[i];
	return os;
}

istream& operator>> (istream& is, Str& s)
{
	s.data.clear();
	
	char c;
	while (is.get(c) && isspace(c))
		;

	if (is)
	{
		do 
			s.data.push_back(c);
		while (is.get(c) && !isspace(c));

		if (is)
			is.unget();
	}
	return is;
}

Str& Str::operator+=(const Str& st)
{
	std::copy(st.data.begin(), st.data.end(), std::back_inserter(data));
	return *this;
}

Str operator+(const Str& a, const Str& b)
{
	Str res = a;
	res += b;
	return res;
}
