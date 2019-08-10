#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int index=0;
    string t;
    cin>>t;
    for(int i = 0;  i < t.length() ; i++){
        if(t[i] == str[index])
            index++;
    }
    cout<<index+1;
    return 0;
}
