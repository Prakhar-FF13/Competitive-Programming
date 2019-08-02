#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    for(int i = 1;  i <= n ; i++)
        cin>>arr[i];
    bool possible = true;
    for(int i = k ; i < n ; i++)
        if(arr[i] != arr[i+1])
            possible = false;
    if(!possible)
        cout<<-1;
    else{
        int i;
        for(i = k-1; i > 0; i--)
            if(arr[i] != arr[k])
                break;
        cout<<i;
    }
    return 0;
}
