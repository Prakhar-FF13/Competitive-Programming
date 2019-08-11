#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    for(int i = str.length()/2 ; i < str.length() ; i++){
        cout<<str[i];
        if(i != str.length() - 1)
            cout<<"+";
    }
    return 0;
}
