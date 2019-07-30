#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    cin>>n>>m;
    ll arr[m];
    for(int i =  0; i < m; i++)
        cin>>arr[i];

    ll timeneeded = arr[0]-1;
    for(int i = 1 ; i < m; i++){
        if(arr[i] < arr[i-1])
            timeneeded += n - (arr[i-1] - arr[i]);
        else
            timeneeded += arr[i] - arr[i-1];
    }
    cout<<timeneeded;
    return 0;
}
