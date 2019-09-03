#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    string str;
    cin>>str;
    int lastR=-1, firstR = -1, lastL=-1, firstL = -1;
    for(int i = 1 ; i < str.length()-1 ; i++){
        if(str[i] == 'R' && firstR == -1)   firstR = i+1;
        if(str[i] == 'L' && firstL == -1)   firstL = i;
        if(str[i] == 'R' && str[i+1] == 'L' && lastR==-1) lastR = i+1;
        if(str[i] == 'R' && str[i+1] == '.' && lastR==-1) lastR = i+1+1;
        if(str[i] == 'L' && str[i+1] == '.' && lastL==-1) lastL = i+1;
    }
    if(firstR == -1){
        cout<<lastL<<" "<<firstL;
    }else if(firstL == -1){
        cout<<firstR<<" "<<lastR;
    }else{
        cout<<firstR<<" "<<firstL;
    }
    return 0;
}
