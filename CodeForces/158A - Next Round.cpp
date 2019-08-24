#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    k--;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    int elem = arr[k];
    int cnt= 0 ;
    for(int i = 0 ; i  <n  ; i++)
        if(arr[i] >= elem && arr[i] > 0)
            cnt++;
    cout<<cnt;
    return 0;
}
