#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n], dp[n+1];
    dp[0] = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        dp[i+1] = dp[i] + arr[i];
    }
    if(n == k){
        cout<<1;
    }else{
        int sum=1000000007, ans=-1;
        for(int i = 1; i <= n-k+1 ; i++){
            int lindex = i + k - 1;
            int findex = i-1;
            if(dp[lindex] - dp[findex] < sum){
                sum = dp[lindex] - dp[findex];
                ans = findex+1;
            }
        }
        cout<<ans;
    }
    return 0;
}
