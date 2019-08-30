#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double angle;
        cin>>angle;
        double n = 360.0/(180 - angle);
        if(n - int(n) == 0.0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
