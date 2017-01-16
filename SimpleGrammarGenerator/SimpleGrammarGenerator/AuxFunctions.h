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
template<class T> bool equal(const T, const T, const T);
template<class T, class P> T find(T, T, const P&);
template<class inputT, class outputT> outputT copy(const inputT, const inputT, const outputT);
template<class inputT, class outputT, class predT> outputT transform(const inputT, const inputT, outputT, predT);
template<class inputT, class T> T accumulate(const inputT, const inputT, T);
template<class inputT, class fwdT> inputT search(inputT, inputT, fwdT, fwdT);
#endif // !AUXFUN_H

