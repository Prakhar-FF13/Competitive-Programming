#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int minele = 1000000009;
    int maxele = -1;
    int minelcnt = 0;
    int maxelcnt = 0;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        if(x < minele){
            minele = x;
            minelcnt = 1;
        }else if(x == minele)
            minelcnt++;

        if(x > maxele){
            maxele = x;
            maxelcnt = 1;
        }else if(x == maxele)
            maxelcnt++;
    }
    long long ans = maxelcnt;
    ans *= minelcnt;
    if(maxele == minele){
        ans = minelcnt;
        ans *= (minelcnt-1);
        ans /= 2;
    }
    cout<<maxele-minele<<" "<<ans;
    return 0;
}
