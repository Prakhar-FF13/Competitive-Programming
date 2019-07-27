#include<bits/stdc++.h>
using namespace std;

bool luckyNumber(string str){
    for(int i = 0 ; i < str.length() ; i++){
        int x = str[i] - '0';
        if(x == 4 || x == 7)
            continue;
        return false;
    }
    return true;
}

int main(){
    string str;
    cin>>str;
    long long cnt = 0;
    for(long long i = 0 ; i < str.length() ; i++)
        if(str[i] == '4' || str[i] == '7')
            cnt++;
            
    string newstr;
    stringstream s;
    s<<cnt;
    newstr = s.str();
    if(luckyNumber(newstr))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}