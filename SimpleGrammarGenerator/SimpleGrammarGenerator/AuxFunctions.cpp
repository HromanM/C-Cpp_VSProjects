#include "stdafx.h"
#include <stdexcept>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include "AuxFunctions.h"

using std::map;
using std::string;
using std::vector;
using std::istream;
using std::domain_error;

/* simple function used to count words and input rows, where it is */
map<string, vector<int> > crossLink(istream& is, vector<string> searchWords(const string&))
{
	map<string, vector<int>> result;
	string oneLine;
	int lineNumber = 0;
	
	while (getline(is, oneLine))
	{
		++lineNumber;
		vector<string> sepWords = searchWords(oneLine);

		for (vector<string>::const_iterator it = sepWords.begin();
			it != sepWords.end(); ++it)
		{
			result[*it].push_back(lineNumber);
		}
	}

	return result;
}

/* sipmpl function used to separate words from one input line */
vector<string> wordSeparator(const string& str)
{
	vector<string> result;
	typedef string::const_iterator iter;

	iter i = str.begin();
	while (i != str.end())
	{
		i = find_if(i, str.end(), isNotASpace);
		iter j = find_if(i, str.end(), isASpace);

		if (i != str.end())
			result.push_back(string(i, j));
		i = j;
	}
	return result;
}

/* aux fc - is char a space? */
bool isASpace(char c)
{
	return isspace(c);
}

/* aux fc - is char not a space? */
bool isNotASpace(char c)
{
	return !isspace(c);
}

/* random number generator */
int randomN(int len)
{
	if (len <= 0 || len > RAND_MAX)
		throw domain_error("wrong argument");

	const int rozsahCasti = RAND_MAX / len;

	int res;
	do res = rand() / rozsahCasti;
	while (res >= len);

	return res;
}

template<class T> bool equal(const T z, const T k, const T z2)
{
	while (z != k)
	{
		if (!(*z++ == *z2++))
			return false;
	}
	return true;
}

template<class T, class P> T find(T b, T e, const P& val)
{
	while (b != e)
	{
		if (*b == *val)
			return b;
		++b;
	}
	return b;
}


template<class inputT, class outputT> outputT copy(const inputT b, const inputT e, const outputT out)
{
	while (b != e)
		*out++ = *b++;
	return out;
}

template<class inputT, class outputT, class predT> outputT transform(const inputT b, const inputT e, outputT out, predT pred)
{
	while (b != e)
	{
		*out++ = pred(*b++);
	}
	return out;
}

template<class inputT, class T> T accumulate(const inputT b, const inputT e, T init)
{
	while (b != e)
	{
		init = *b++;
	}
	return init;
}

template<class inputT, class fwdT> inputT search(inputT b, inputT e, inputT b2, inputT e2)
{
	fwdT it = b2;
	inputT ret = b;
	while (b != e)
	{
		if (*b++ == *it++)
		{
			if (it == e2)
				return ret;
		}
		else
		{
			it = b2;
			ret = b;
		}
	}
	return e;
}