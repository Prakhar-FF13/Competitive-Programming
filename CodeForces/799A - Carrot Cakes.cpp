#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int time1 = 0;
    int temp=n;
    while(temp > 0){
        temp -= k;
        time1 += t;
    }
    int time2 = 0;
    temp = n;
    while(temp > 0){
        temp -= k;
        time2 += t;
        if(time2 >= d)
            break;
    }
    if(time2 - d != 0)
        t = time2 - d;
    else k *= 2;
    while(temp > 0){
        temp -= k;
        time2 += t;
    }
    if(time1 <= time2)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
