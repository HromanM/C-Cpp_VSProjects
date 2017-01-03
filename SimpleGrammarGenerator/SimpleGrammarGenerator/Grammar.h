#ifndef GRAMMAR_H_WATCHER
#define GRAMMAR_H_WATCHER

#include <map>
#include <vector>
#include <iostream>
#include <string>


typedef std::vector<std::string> Rule;
typedef std::vector<Rule> RuleContainer;
typedef std::map<std::string, RuleContainer> Grammar;

Grammar readGrammar(std::istream&);

// fc used to generate grammar from sentence
std::vector<std::string> sentenceGenerator(const Grammar&); 

// fc usec to generate one sentence from grammar
void oneSentGen(const Grammar&, const std::string&, std::vector<std::string>&);

//fc used to check if string is rule or final word
bool isRule(const std::string&);

#endif