/***************************************************
	aux fc
***************************************************/

#ifndef AUX_FUN_H
#define AUX_FUN_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::vector<int>> crossLink(std::istream&, std::vector<std::string> searchWords(const std::string&) = wordSeparator);
std::vector<std::string> wordSeparator(const std::string&);

#endif // !AUXFUN_H

