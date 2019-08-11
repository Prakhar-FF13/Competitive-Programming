#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,b,d;
    cin>>n>>b>>d;
    int arr[n];
    for(int i = 0 ; i  < n ; i++)
        cin>>arr[i];
    int cnt=0,sum=0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= b){
            sum += arr[i];
        }
        if(sum > d){
            sum = 0;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
