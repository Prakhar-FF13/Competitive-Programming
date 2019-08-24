#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    int maxel = -1, minel = 1000000004;
    for(int i = 0 ; i <  n ; i++){
        int x;
        cin>>x;
        arr[i] = x;
        maxel = max(maxel, x);
        minel = min(minel, x);
    }
    if(n <= 2)
        cout<<0;
    else{
        int maxelocc=0, minelocc = 0;
        for(int i = 0 ; i <  n ; i++){
            if(arr[i] == maxel) maxelocc++;
            if(arr[i] == minel) minelocc++;
        }
        int ans = n - (maxelocc+minelocc);
        if(ans < 0) ans = 0;
        cout<<ans;
    }
    return 0;
}
