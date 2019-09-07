#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nCr(ll n, ll m){
    if(n-m < m) m = n-m;
    ll res = 1;
    ll denom = 1;
    for(ll i = n ; i > n-m ; i--){
        //cout<<i<<" "<<denom<<endl;
        res = (res * i)/denom;
        denom++;
    }
    return res;
}

int main(){
    ll n,m;
    while(cin>>n>>m){
        if(n==0) break;
        cout<<n<<" things taken "<<m<<" at a time is "<<nCr(n, m)<<" exactly.\n";
    }
    return 0;
}
