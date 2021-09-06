#ifndef REDACT_H
#define REDACT_H

#include<string>
using std::string;
#include<vector>
using std::vector;

string redact_all_chars(const string&);
string redact_alphabet_digits(const string&);
string redact_words(const string&, const vector<string>&);

#endif
