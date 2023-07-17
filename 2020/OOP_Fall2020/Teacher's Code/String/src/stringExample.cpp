#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "./chk_string.h"

using namespace std;

int main() {
    string input;
    cin >> input;

    char* example = new char[5];
    delete[] example;

    checkError(input);

    vector<int> output = checkUpper(input);
    for(int x : output){
      cout<<x<<endl;
    }
    return 0;
}
