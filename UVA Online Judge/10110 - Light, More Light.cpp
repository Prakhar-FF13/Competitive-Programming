#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        cin>>n;
        if(n == 0)
            break;
        int sq = sqrt(n);
        if(sq*sq == n)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
