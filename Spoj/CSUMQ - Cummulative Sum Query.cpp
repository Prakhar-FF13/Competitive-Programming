#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr[n+1];
    arr[0] = 0;
    for(int i =1; i<= n ; i++){
        cin>>arr[i];
        arr[i] += arr[i-1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l++, r++;
        cout<<arr[r]-arr[l-1]<<endl;
    }
    return 0;
}
