#include<bits/stdc++.h>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    cin>>str;
    int cntup = 0;
    int cntlow = 0;
    for(int i = 0 ; i < str.length() ; i++){
        if(isupper(str[i]))
            cntup++;
        else
            cntlow++;
    }
    if(cntup > cntlow)
        transform(str.begin(), str.end(), str.begin(), ::toupper);
    else
        transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str;
    return 0;
}