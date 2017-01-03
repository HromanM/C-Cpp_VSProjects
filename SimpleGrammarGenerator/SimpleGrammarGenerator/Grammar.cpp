#include "stdafx.h"
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "Grammar.h"
#include "AuxFunctions.h"
#include <stdexcept>

using namespace std;

Grammar readGrammar(istream& is)
{
	Grammar result;
	string oneLine;

	while (getline(is, oneLine))
	{
		vector<string> sepWords = wordSeparator(oneLine);
		if (!sepWords.empty())
			result[sepWords[0]].push_back(Rule(sepWords.begin() + 1, sepWords.end()));
	}

	return result;
}

/* sentence generator */
vector<string> sentenceGenerator(const Grammar& gram)
{
	vector<string> result;
	oneSentGen(gram, "<veta>", result);
	return result;
}

/* check is string is rule */
bool isRule(const string& s)
{
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void oneSentGen(const Grammar& gram, const string& oneWord, vector<string>& result)
{
	if (gram.empty())
		throw invalid_argument("grammar is empty");

	if (!isRule(oneWord))
		result.push_back(oneWord);
	else
	{
		Grammar::const_iterator iter = gram.find(oneWord);
		if (iter == gram.end())
			throw logic_error("no rule for this word");

		const RuleContainer& rules = iter->second;
		const Rule& rule = rules[randomN(rules.size())];
		
		for (Rule::const_iterator it = rule.begin(); it != rule.end(); ++it)
		{
			oneSentGen(gram, *it, result);
		}
	}
}

