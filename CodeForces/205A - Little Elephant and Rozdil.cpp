#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll cnt=0;
    ll arr[n];
    ll maxdist = ll(1e16);
    ll index;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        if(arr[i] < maxdist){
            maxdist = arr[i];
            index = i+1;
            cnt=0;
        }
        if(arr[i] == maxdist){
            cnt++;
        }
    }
    if(cnt==1)
        cout<<index;
    else
        cout<<"Still Rozdil";
    return 0;
}
