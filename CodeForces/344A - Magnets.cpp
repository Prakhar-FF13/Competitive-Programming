#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string magnet="", prev="";
    int grpcnt = 1;
    for(int i = 0 ; i < n ; i++){
        cin>>magnet;
        if(prev == "")
            prev = magnet;
        else if(prev != magnet){
            grpcnt++;
            prev = magnet;
        }
    }
    cout<<grpcnt;
    return 0;
}
