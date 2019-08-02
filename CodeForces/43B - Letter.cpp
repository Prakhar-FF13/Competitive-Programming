#include<bits/stdc++.h>
using namespace std;

int main(){
    string heading, text;
    getline(cin, heading);
    getline(cin, text);
    map<char, int> m;
    for(int i = 0 ; i < heading.length() ; i++)
        if(heading[i] == ' ') continue;
        else{
            if(m[heading[i]]) m[heading[i]]++;
            else m[heading[i]] = 1;
        }
    bool possible=true;
    for(int i = 0; i < text.length() ; i++)
        if(text[i] == ' ') continue;
        else{
            if(m[text[i]] && m[text[i]] > 0) m[text[i]]--;
            else{ possible = false; break;}
        }
    if(!possible) cout<<"NO"; else cout<<"YES";
    return 0;
}
