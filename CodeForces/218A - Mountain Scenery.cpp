#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[2*n+5];
    for(int i = 1 ; i <= 2*n+1 ; i++)
        cin>>arr[i];
    for(int i = 2; i <= 2*n ; i += 2){
        if(k > 0 && arr[i] > arr[i-1] + 1 && arr[i] > arr[i+1] + 1){
            k--;
            arr[i]--;
        }
    }
    cout<<arr[1];
    for(int i = 2; i<= 2*n+1 ; i++)
        cout<<" "<<arr[i];
    return 0;
}
