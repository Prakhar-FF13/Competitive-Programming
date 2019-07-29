#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int ansx, ansy;
    int diff=1000000007;
    for(int i = 0 ;  i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < n ; i++){
        int dx = abs(arr[i] - arr[(i+1)%n]);
        if(dx < diff){
            diff = dx;
            ansx = i;
            ansy = (i+1)%n;
        }
    }
    for(int i = n-1 ; i>0 ; i--){
        int dx = abs(arr[i] - arr[i-1]);
        if(dx < diff){
            diff = dx;
            ansx = i-1;
            ansy = (i);
        }
    }
    if(abs(arr[0]-arr[n-1]) < diff){
        ansx = 0;
        ansy = n-1;
    }
    cout<<ansx+1<<" "<<ansy+1;
}
