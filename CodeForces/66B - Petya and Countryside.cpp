#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++)
        cin>>arr[i];
    int ans = 0;
    for(int i = 0 ; i  < n ; i++){
        int cnt = 1;
        int j = i;
        while(j-1 >= 0 && arr[j-1] <= arr[j])   j--, cnt++;
        j = i;
        while(j+1 < n && arr[j+1] <= arr[j])    j++, cnt++;
        ans = max(ans, cnt);
    }
    cout<<ans;
    return 0;
}
