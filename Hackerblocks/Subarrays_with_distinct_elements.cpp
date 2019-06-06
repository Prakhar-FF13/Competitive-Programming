#include<bits/stdc++.h>
using namespace std;
#define MOD int(1e9+7)
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i <  n ; i++){
        cin>>arr[i];
    }
    set<int> s;
    long long ans = 0 ;
    int j = 0;
    for(int i = 0 ; i < n ; i++){
        while(j < n && s.find(arr[j]) == s.end()){
            s.insert(arr[j]);
            j++;   
        }
        ans = ans + ((j-i) * (j-i+1)/2);
        ans %= MOD;
        s.erase(arr[i]);
    }
    cout<<ans;
	return 0;
}
