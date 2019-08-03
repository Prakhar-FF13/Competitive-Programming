#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    string ans="";
    int removpos = false;
    bool removed = false;
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '0' && !removed){
            removed=true; continue;
        }else{
            ans += str[i];
        }
    }
    if(ans.length() == str.length()){
        for(int i = 0 ; i < str.length()-1 ; i++)
            cout<<ans[i];
    }else{
        cout<<ans;
    }
    return 0;
}
