#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    set<char> count;
    for(int i = 0; i < str.length() ; i++)
        count.insert(str[i]);

    int x = count.size();
    if(x&1) cout<<"IGNORE HIM!";
    else    cout<<"CHAT WITH HER!";
    return 0;
}
