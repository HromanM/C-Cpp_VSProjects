/***************************************************
	aux fc
***************************************************/

#ifndef AUX_FUN_H
#define AUX_FUN_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

bool isASpace(char);
bool isNotASpace(char);
std::vector<std::string> wordSeparator(const std::string&);
std::map<std::string, std::vector<int> > crossLink(std::istream&, std::vector<std::string> searchWords(const std::string&) = wordSeparator);


#endif // !AUXFUN_H

