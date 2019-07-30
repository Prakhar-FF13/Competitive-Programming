#include<bits/stdc++.h>
using namespace std;
int main(){
    string ber, bir;
    cin>>ber>>bir;
    reverse(ber.begin(), ber.end());
    if(ber == bir)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
