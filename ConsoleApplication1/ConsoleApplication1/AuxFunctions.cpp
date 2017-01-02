#include "stdafx.h"
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