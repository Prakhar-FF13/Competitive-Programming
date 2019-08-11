#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    char c = 'a';
    for(int i = 0 ; i < n ; i++){
        cout<<c;
        int x = c - 'a';
        x  = (x + 1)%k;
        c = x + 'a';
    }
    return 0;
}
