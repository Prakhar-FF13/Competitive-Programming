#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod;
ll powerMod(ll num, ll p){
    ll res = 1;
    while(p){
        if(p & 1)
            res = (res * num)%mod;
        num = (num * num)%mod;
        p = p>>1;
    }
    return res;
}
int main(){
    ll b,p;
    while(cin>>b>>p>>mod){
        cout<<powerMod(b, p)<<endl;
    }
    return 0;
}
