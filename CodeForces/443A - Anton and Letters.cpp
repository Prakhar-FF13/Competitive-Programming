#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    set<char> cnt;
    for(int i = 0 ; i < str.length() ; i++){
        char c = str[i];
        if( c >= 'a' && c <= 'z' )
            cnt.insert(c);
    }
    cout<<cnt.size();
    return 0;
}
