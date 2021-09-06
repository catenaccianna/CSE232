#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<iomanip>
#include<algorithm>
#include<string>
using std::string; using std::getline;
#include<vector>
using std::vector; 
#include<sstream>
using std::istringstream; using std::ostringstream;

void split(const string &s, vector<string> &elems) {
    istringstream iss(s);
    string item;
    while(getline(iss, item, ' '))
      elems.push_back(item);
} //function copy and pasted from a lecture video


int main(){
  string current_line;
  vector<string> input_temp;
  vector<vector<string>> input;
  
  //https://www.cplusplus.com/forum/general/179626
  //read in all of the lines and store them in input_temp vector
  while(getline(cin, current_line)){
    input_temp.push_back(current_line);
  }
  
  vector<string> output;
  string developing_output="";
  
  //use split function to seperate words in a a line by spaces
  for(int i=0; i< static_cast<int>(input_temp.size()); ++i){
    vector<string> current;
    split(input_temp[i], current);
    input.push_back(current);
  }
  
  //compare words and if they have letter overlaps, 
  //create a new word with overlap and delete one of 
  //the old ones
  for(int i=0; i< static_cast<int>(input.size()); ++i){
    developing_output="";
  for(int j=0; j< static_cast<int>(input[i].size())-1; ++j){
    
    string s1=input[i][j];
    string s2=input[i][j+1];
    
    if(s1.length()>=5 &&s2.length()>=5 &&s1.substr(s1.length()-5)==s2.substr(0,5)){
      string change=s1.substr(0,(s1.length()-5))+s2;
      input[i][j]=change;
      input[i].erase(input[i].begin()+j+1);
      --j;
    }
    else if(s1.length()>=4 &&s2.length()>=4 &&s1.substr(s1.length()-4)==s2.substr(0,4)){
      string change=s1.substr(0,(s1.length()-4))+s2;
      input[i][j]=change;
      input[i].erase(input[i].begin()+j+1);
      --j;
    }
    else if(s1.length()>=3 &&s2.length()>=3 && s1.substr(s1.length()-3)==s2.substr(0,3)){
      string change=s1.substr(0,(s1.length()-3))+s2;
      input[i][j]=change;
      input[i].erase(input[i].begin()+j+1);
      --j;
    }
    else if(s1.length()>=2 &&s2.length()>=2 && s1.substr(s1.length()-2)==s2.substr(0,2)){
      string change=s1.substr(0,(s1.length()-2))+s2;
      input[i][j]=change;
      input[i].erase(input[i].begin()+j+1);
      --j;
    }
    else if(s1.length()>=1 &&s2.length()>=1 && s1.substr(s1.length()-1)==s2.substr(0,1)){
      string change=s1.substr(0,(s1.length()-1))+s2;
      input[i][j]=change;
      input[i].erase(input[i].begin()+j+1);
      --j;
    }
    else{
      continue;
    }
      
  }
  
  //create a vector we add each of the final words to
  for(int j=0; j<static_cast<int>(input[i].size()); ++j){
    developing_output+=input[i][j];
    developing_output+=" ";
  }
  output.push_back(developing_output);
  
  }
  
  //print outputs
  for(int i=0; i< static_cast<int>(output.size()); ++i){
    cout<<output[i]<<endl;
  }
} 
