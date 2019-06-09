#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    int arr[65] = {0};
    while(n--){
        long long x,i=0;
        cin>>x;
        while(x){
            if(x & 1)
                arr[i]++;
            i++;
            x = x>>1;
        }
    }
    long long ans = 0;
    for(int i = 0 ; i < 64; i++){
        arr[i] %= 3;
        if(arr[i]){
            ans = ans | (1<<(i));
        }
    }
    cout<<ans;
	return 0;
}
