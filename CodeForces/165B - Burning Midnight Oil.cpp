#include<bits/stdc++.h>
using namespace std;

bool isPossible(int n, int k, int v){
    int cnt = v;
    while(v){
        v = v/k;
        cnt += v;
    }
    if(cnt >= n)    return true;
    else            return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    int low = 1;
    int high = 1e9;
    int ans = 1e9;
    while(low <= high){
        int mid = high - (high - low)/2;
        if(isPossible(n, k, mid)){
            ans = min(ans, mid);
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans;
    return 0;
}
