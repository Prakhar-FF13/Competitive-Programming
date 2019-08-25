#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=0;
    while(n--){
        string str;
        cin>>str;
        if(str[0] == '+' || str[2] == '+')
            cnt++;
        if(str[0] == '-' || str[2] == '-')
            cnt--;
    }
    cout<<cnt;
    return 0;
}
