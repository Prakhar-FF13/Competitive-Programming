#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    for(int i = 0 ; i < str.length() ; i++){
        int x = str[i] - '0';
        int y = 9 - x;
        if(y < x){
            if(y != 0) str[i] = y + '0';
            else if(i!=0) str[i] = y + '0';
        }
    }
    cout<<str;
    return 0;
}
