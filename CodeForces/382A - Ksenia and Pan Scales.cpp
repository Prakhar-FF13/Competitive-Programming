#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    string str2;
    cin>>str2;
    string arr[2];
    arr[0] = ""; arr[1] = "";
    int ind=0;
    for(int i=0; i<str.length() ;i++){
        if(str[i] == '|') { ind++; continue;}
        arr[ind] += str[i];
    }
    int u = 0;
    while(arr[0].length() != arr[1].length() && u < str2.length()){
        if(arr[0].length() < arr[1].length()) ind=0;
        else ind=1;
        arr[ind] += str2[u++];
    }
    ind = 0;
    while(u < str2.length()){
        arr[ind] += str2[u++];
        ind = 1 - ind;
    }
    if(arr[0].length() != arr[1].length()) cout<<"Impossible";
    else cout<<arr[0]<<"|"<<arr[1];
    return 0;
}
