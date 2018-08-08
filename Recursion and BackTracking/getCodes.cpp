/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
You are given a numeric string S. Write a program to return the list of all possible codes
that can be generated from the given string.
*/


#include <string.h>
#include<bits/stdc++.h>
using namespace std;

map<int, char> m;

int getCodeHelper(string input, string output[10000], string str, int* k){
   	
    if(input.length() == 0){
      int c = *k;
      output[c] = str;
      *k = ++c;
      return 1;
    }
    int ans = 0;
  	if(input[0]){
      int x = input[0] - '0';
      char c = m[x];
      ans += getCodeHelper(input.substr(1), output, str + c, k);
    }
    if(input[0] && input[1]){
      int x1 = input[0] - '0';
      int x2 = input[1] - '0';
      int x = x1*10 + x2;
      char c = m[x];
      if(c >= 'a' && c <= 'z')
        ans += getCodeHelper(input.substr(2), output, str + c, k);
    }
    return ans;
}


int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
   int c = 0;
   for(int i = 1; i <= 26 ; i++){
     int x = i - 1;
     char c = x + 'a';
     m[i] = c;
   }
  /*for(int i = 1; i <= 26 ; i++){
     cout<<i<<" "<<m[i]<<"\n";
   }*/
   int ans = getCodeHelper(input, output, "", &c);
  
   /*for(int i = 0; i < ans ; i++)
     cout<<output[i]<<"\n";*/
   return ans;
  
  return 0;
}

int main(){
  string str;
  cin>>str;
  string out[10000];
  int ans = getCodes(str, out);
  for(int i = 0 ; i < ans ; i++)
    cout<<out[i]<<"\n";
}

