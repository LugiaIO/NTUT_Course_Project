#include "./chk_string.h"

void checkError(string input) {
  int x = 0;
    for(char ch:input){
      if(!(isalpha(ch))){
        //throw string("checkError"); // object of string class
        throw invalid_argument(__func__);
        //throw "Error"; // char * = char[]
        //throw invalid_argument(__func__);
      }
  }
}

int checkAlpha(string input) {
  for(char ch:input){
    if(!(isalpha(ch))){
      return 1;
    }
  }
  return 0;
}

vector<int> checkUpper(string input){
  int len = input.length();
  int upLow[len];
  for(int i = 0; i < len; i++){
    if(isupper(input[i])){
      upLow[i] = 0;
    } else{
      upLow[i] = 1;
    }
  }
  int value = upLow[0];
  int temp = 0;
  vector<int> output;
  for(int j = 0; j < len; j++){
    value = upLow[j];
    if(value == 0){
      temp++;
    } else {
      if(temp > 0){
        output.push_back(temp);
      }
      temp = 0; //temp reset
    }
  }
  if(temp != 0){
    output.push_back(temp);
  }
  return output;
}
