#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int t = n/7;
    for(int i = 0 ; i < t ; i++){
        cout<<"VIBGYOR";
    }
    n = n%7;
    if(n==1)
        cout<<"G";
    else if(n==2)
        cout<<"GY";
    else if(n==3)
        cout<<"GYO";
    else if(n==4)
        cout<<"GYOR";
    else if(n==5)
        cout<<"GYORG";
    else if(n==6)
        cout<<"GYORGY";
    return 0;
}
