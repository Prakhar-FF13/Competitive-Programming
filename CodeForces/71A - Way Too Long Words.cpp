#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i <  n ; i++){
        string str;
        cin>>str;
        if(str.length() > 10)
            cout<<str[0]<<str.length()-2<<str[str.length()-1]<<"\n";
        else
            cout<<str<<"\n";
    }
    return 0;
}
