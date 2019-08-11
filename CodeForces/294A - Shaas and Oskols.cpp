#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+4];
    arr[0] = arr[n+1] = 0;
    for(int i = 1; i <= n ; i++)
        cin>>arr[i];

    int m;
    cin>>m;
    while(m--){
        int xi, yi;
        cin>>xi>>yi;
        int left = yi - 1 - 1 + 1;
        int right = arr[xi] - (yi + 1) + 1;
        arr[xi] = 0;
        arr[xi-1] += left;
        arr[xi+1] += right;
    }
    for(int i = 1; i <= n; i++)
        cout<<arr[i]<<"\n";
    return 0;
}
