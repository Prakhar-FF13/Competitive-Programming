#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int  i = 0 ; i <  n ; i++)
        cin>>arr[i];

    int cnt[2] = {0,0}, i=0, j=n-1;
    int plturn=0;
    while(i <= j){
        if(arr[i] > arr[j]){cnt[plturn] += arr[i];i++;}
        else{cnt[plturn] += arr[j];j--;}
        plturn = 1 - plturn;
    }
    cout<<cnt[0]<<" "<<cnt[1];
    return 0;
}
