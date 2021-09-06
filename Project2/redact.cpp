#include "redact.h"
#include<string>
#include<vector>
using std::string; using std::vector;
#include<algorithm>

string redact_all_chars(const string& input){
    string output="";
    for(auto i:input){
        output+="#";
    }
    return output;
}

string redact_alphabet_digits(const string& input){
    string output="";
    for(auto i:input){
        if((i>47&&i<58)||(i>64&&i<91)||(i>96&&i<122)){
            output+="#";
        }
        else{
            output+=i;
        }
    }
    return output;
}
string redact_words(const string& input, const vector<string>& words_to_redact){
    string output=input;
    for(auto i:words_to_redact){
        size_t start_pos = 0;
        while((start_pos = output.find(i, start_pos)) != std::string::npos) {
            string replace_w="";
            for(int j=0; j<i.length(); ++j){
                replace_w+="#";
            }
            output.replace(start_pos, i.length(), replace_w);
        start_pos += i.length(); 
        }
    }
    return output;
}
//https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
