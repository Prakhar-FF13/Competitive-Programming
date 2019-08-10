#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int cnta = 0, cntd = 0;
    for(int i = 0 ; i < str.length() ; i++)
        if(str[i] == 'A') cnta++;
        else              cntd++;

    if(cnta > cntd) cout<<"Anton";
    else if(cntd > cnta) cout<<"Danik";
    else cout<<"Friendship";
    return 0;
}
