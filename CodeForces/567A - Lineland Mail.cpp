#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    for(int i = 0 ; i  < n ; i++){
        if(i == 0)
            cout<<abs(arr[i+1] - arr[i])<<" "<<abs(arr[n-1] - arr[i])<<"\n";
        else if(i == n-1)
            cout<<abs(arr[i] - arr[i-1])<<" "<<abs(arr[i] - arr[0])<<"\n";
        else{
            int mindis = min(abs(arr[i] - arr[i-1]), abs(arr[i+1] - arr[i]));
            int maxdis = max(abs(arr[i] - arr[0]), abs(arr[n-1] - arr[i]));
            cout<<mindis<<" "<<maxdis<<"\n";
        }
    }
    return 0;
}
