#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int arr[200005];
    for(int i = 0 ; i < 200005; i++)    arr[i] = 0;

    for(int i = 0; i < n ; i++){
        int l,r;
        cin>>l>>r;
        arr[l] += 1;
        arr[r+1] += -1;
    }

    for(int i = 1 ; i < 200005; i++)  arr[i] += arr[i-1];
    for(int i = 1 ; i < 200005; i++) if(arr[i] >= k) arr[i] = 1; else arr[i] = 0;
    for(int i = 1 ; i < 200005; i++)  arr[i] += arr[i-1];

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<arr[r] - arr[l-1]<<endl;
    }

    return 0;
}
