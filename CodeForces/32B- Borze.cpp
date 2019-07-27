#include<bits/stdc++.h>
using namespace std;

int main(){
        string str;
        cin>>str;
        string ans="";
        for(int  i = 0 ; i < str.length(); i++){
            char c = str[i];
            if(c == '.')
                ans += "0";
            else{
                c = str[i+1];
                if(c == '.')
                    ans += "1";
                else
                    ans += "2";
                i++;
            }
            
        }
        cout<<ans;
        return 0;
}