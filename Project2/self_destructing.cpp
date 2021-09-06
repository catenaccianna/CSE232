#include "self_destructing.h"
#include "redact.h"
#include <string>
#include <vector>
#include <ios>
using std::string; using std::vector;
#include<sstream>
using std::ostringstream; using std::istringstream;
#include<ostream>
#include<istream>
using std::ostream; using std::istream; using std::endl;
#include <stdexcept>
#include<algorithm>


SelfDestructingMessage::SelfDestructingMessage(vector<string> m, long n){
    messages=m;
    number_of_allowed_views=n;
     for(int i=0; i<messages.size(); ++i){
            allowed_views.push_back(number_of_allowed_views);
        }
}  


int SelfDestructingMessage::size(){
    return messages.size();
}


vector<string> SelfDestructingMessage::get_redacted(){
    vector<string> output;
    for(auto i:messages){
        output.push_back(redact_alphabet_digits(i));
    }
    return output;
}


long SelfDestructingMessage::number_of_views_remaining(size_t index){
    return allowed_views[index];
}


const string& SelfDestructingMessage::operator[](size_t index) {
    int size_var=messages.size();
    if (index >= size_var) { 
        throw std::out_of_range ("Index out of range");
    } 
    else if(allowed_views[index]==0){
        throw std::invalid_argument( "This message has no more views availible." );
    }
    else{
        allowed_views[index]=allowed_views[index]-1;
        return messages[index]; 
    }
} 
  
  
istream & operator>>(istream &in, SelfDestructingMessage& m) {
    string this_line;
    std::getline(in, this_line);
    m.messages.push_back(this_line);
    m.allowed_views.push_back(m.number_of_allowed_views);
    return in;
}


SelfDestructingMessage::SelfDestructingMessage(SelfDestructingMessage &m){ 
  messages=m.messages;
  allowed_views=m.allowed_views;
  number_of_allowed_views=m.number_of_allowed_views;
  vector<string> loop_max=m.messages;
  for(int i=0; i<loop_max.size(); ++i){
      m.allowed_views.at(i)=0;
  }
}


SelfDestructingMessage& SelfDestructingMessage::operator=(SelfDestructingMessage &m){
    messages=m.messages;
    allowed_views=m.allowed_views;
    number_of_allowed_views=m.number_of_allowed_views;
    vector<string> loop_max=m.messages;
    for(int i=0; i<loop_max.size(); ++i){
        m.allowed_views.at(i)=0;
    }
    return *this;
}
//https://stackoverflow.com/questions/40579676/c-creating-a-copy-constructor-for-stack-class


void SelfDestructingMessage::add_array_of_lines(string * ary, long size){
    for (string *p = ary; p < (ary + size); ++p){
        allowed_views.push_back(number_of_allowed_views);
        messages.push_back(*p);
    }
}


ostream& operator<<(ostream& out, SelfDestructingMessage& m){
    vector<string> to_print= m.get_redacted();
    int sz=to_print.size();
    for(int i=0; i<sz; ++i){
        out<<"0"<<m.allowed_views[i]<<": "<<to_print[i]<< std::endl;
    }
    return out; 
}
