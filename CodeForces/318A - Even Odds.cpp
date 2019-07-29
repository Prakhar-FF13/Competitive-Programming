#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
    cin>>n>>k;
    ll numOfEvens = n/2;
    ll numOfOdds  = n - numOfEvens;
    if(k <= numOfOdds){
        cout<<(1 + (k-1)*2);
    }else{
        k -= numOfOdds;
        cout<<(2 + (k-1)*2);
    }
    return 0;
}
