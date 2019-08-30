#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    long long rows = n/k;
    if(n%k != 0) rows += 1;
    long long cols = m/k;
    if(m%k != 0) cols += 1;
    cout<<rows * cols;

    return 0;
}
