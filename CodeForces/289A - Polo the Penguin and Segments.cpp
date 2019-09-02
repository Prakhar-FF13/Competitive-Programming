#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    long long numx = 0;
    while(n--){
        int l,r;
        cin>>l>>r;
        int xs = (r - l + 1);
        numx += xs;
    }
    int nearest = numx%k;
    cout<<(k - nearest)%k;
}
