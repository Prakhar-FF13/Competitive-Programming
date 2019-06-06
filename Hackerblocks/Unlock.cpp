#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int arr[n], pos[n+1];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        pos[arr[i]] = i;
    }
    int ind = 0;
    while(k && ind < n){
        if(arr[ind] == n-ind){
            ind++;
            continue;
        }
            
        int elempos = pos[n-ind];

        pos[arr[ind]] = pos[n-ind];
        pos[n-ind] = ind;

        swap(arr[ind], arr[elempos]);

        k--;
        ind++;
    }    
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
	return 0;
}
