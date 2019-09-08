#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    long long arr[n+1], sarr[n+1];
    arr[0] = 0; sarr[0] = 0;
    for(int i = 1 ; i  <= n ; i++){
        cin>>arr[i];
        sarr[i] = arr[i];
    }
    sort(sarr, sarr+n+1);
    for(int i = 1; i <=n ; i++){
        arr[i] += arr[i-1];
        sarr[i] += sarr[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1) cout<<arr[r]-arr[l-1]<<endl;
        else        cout<<sarr[r]-sarr[l-1]<<endl;
    }
    return 0;
}
