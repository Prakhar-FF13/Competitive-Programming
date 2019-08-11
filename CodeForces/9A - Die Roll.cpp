#include<bits/stdc++.h>
using namespace std;

int gcd(int n, int m){
    if(m == 0)
        return n;
    return gcd(m, n%m);
}

int main(){
    int x,y;
    cin>>x>>y;
    int numbs = 6 - max(x,y) + 1;
    int g = gcd(numbs, 6);
    if(numbs == 0) cout<<"0/1";
    else if(numbs == 6) cout<<"1/1";
    else{
        numbs /= g;
        cout<<numbs<<"/"<<int(6/g);
    }
    return 0;
}
