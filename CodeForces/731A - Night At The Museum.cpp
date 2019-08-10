#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int rots = 0;
    int p = 0;
    for(int i = 0 ;  i < str.length() ; i++){
        int x = str[i] - 'a';
        int first;
        if(x >= p) first = x - p;
        else first = p - x;
        int second = 26 - first;
        //cout<<first<<" "<<second<<"\n";
        rots += min(first, second);
        p = x;
    }
    cout<<rots;
    return 0;
}
