#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[5];
    for(int i = 0; i < 5;  i++)   arr[i] = 0;
    for(int i = 1; i <= m; i++)   arr[i%5]++;
    long long ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int x = i%5;
        int y = (5 - x)%5;
        ans += arr[y];
    }
    cout<<ans;
    return 0;
}
