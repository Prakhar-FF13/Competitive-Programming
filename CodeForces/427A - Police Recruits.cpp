#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int crimes=0;
    int police = 0;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        if(x==-1 && police==0)
            crimes++;
        else if(x==-1 && police > 0)
            police--;
        else
            police += x;
    }
    cout<<crimes;
    return 0;
}
