#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,r;
    cin>>k>>r;
    int cnt=1;
    int temp=k;
    while(temp%10 != 0 && temp%10 != r){
        cnt++;
        temp=k*cnt;
    }
    cout<<cnt;
}
