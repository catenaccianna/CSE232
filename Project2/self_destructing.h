#ifndef SELF_DESTRUCTING_H
#define SELF_DESTRUCTING_H

#include <string>
#include <vector>
#include <ios>
#include<sstream>
#include<ostream>
#include<istream>
using std::string; using std::vector;
using std::ostringstream; using std::istringstream;
using std::ostream; using std::istream; using std::endl;

class SelfDestructingMessage {
    
    private:
    vector<string> messages;
    vector<long> allowed_views;
    long number_of_allowed_views;
    
    public:
    SelfDestructingMessage()=default;
    SelfDestructingMessage(vector<string> m, long n);

    int size();
    vector<string> get_redacted();
    long number_of_views_remaining(size_t);
    const string & operator[](size_t); 
    void add_array_of_lines(string * ary, long size);
    friend ostream & operator<<(ostream &, SelfDestructingMessage&);
    friend istream & operator>>(istream &, SelfDestructingMessage&);
    SelfDestructingMessage& operator=(SelfDestructingMessage&);
    SelfDestructingMessage(SelfDestructingMessage&);
    
};

ostream & operator<<(ostream& out, SelfDestructingMessage& m);
istream & operator>>(istream& in, SelfDestructingMessage& m);

#endif
