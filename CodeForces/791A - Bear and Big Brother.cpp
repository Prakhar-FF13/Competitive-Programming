#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(a == b)
        cout<<1;
    else{
        int cnt=0;
        while(a<=b){
            a *= 3;
            b *= 2;
            cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
