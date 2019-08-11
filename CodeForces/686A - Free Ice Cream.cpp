#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    long long ice = 0, diss = 0;
    cin>>n>>x;
    ice = x;
    //fflush(stdin);
    while(n--){
        char c;
        long long d;
        cin>>c>>d;
        //fflush(stdin);
        if(c == '+') ice += d;
        else if(ice >= d) ice -= d;
        else diss++;
    }
    cout<<ice<<" "<<diss;
    return 0;
}
