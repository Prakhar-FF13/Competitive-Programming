#include<bits/stdc++.h>
using namespace std;

string solve(string str){
    long long ans = 0;
    for(int i = 0 ; i < str.length() ; i++){
        ans += (str[i] - '0');
    }
    return to_string(ans);
}

int main(){
    string str;
    cin>>str;
    int cnt = 0;
    while(str.length() != 1){
        str = solve(str);
        cnt++;
    }
    cout<<cnt;
}
