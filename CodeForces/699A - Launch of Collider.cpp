#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    string dir;
    cin>>dir;
    int coord[n];
    for(int i = 0 ; i < n ;  i++)
        cin>>coord[i];
    long long ans = (1e15);
    for(int i = 0 ; i < n-1; i++){
        if(dir[i] == 'R' && dir[i+1] == 'L'){
            long long midway = (coord[i+1] + coord[i])/2;
            midway = coord[i+1] - midway;
            ans = min(ans, midway);
        }
    }
    if(ans == 1e15) cout<<-1;
    else            cout<<ans;
    return 0;
}
