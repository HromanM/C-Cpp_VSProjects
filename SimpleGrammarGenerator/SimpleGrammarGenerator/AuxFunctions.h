/***************************************************
	aux fc
***************************************************/

#ifndef AUX_FUN_H
#define AUX_FUN_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>


bool isASpace(char);
bool isNotASpace(char);
std::vector<std::string> wordSeparator(const std::string&);
std::map<std::string, std::vector<int> > crossLink(
std::istream&, std::vector<std::string> searchWords(const std::string&) = wordSeparator);

// random number generator
int randomN(int);

#endif // !AUXFUN_H

