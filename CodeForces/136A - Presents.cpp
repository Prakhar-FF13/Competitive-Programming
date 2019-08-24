#include<bits/stdc++.h>
using namespace std;

int arr[101];
int arr2[101];
int n;
int main(){
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
    }
    for(int i = 1 ; i <= n ; i++){
        arr2[arr[i]] = i;
    }
    for(int i = 1 ; i <= n ; i++)
        cout<<arr2[i]<<" ";
    return 0;
}
