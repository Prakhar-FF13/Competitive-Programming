#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(1){
        cin>>n;
        if(n == 0)
            break;
        int toggle=0;
        for(int i = 1 ; i <= n ; i++){
            if(n%i == 0) toggle = 1 - toggle;
        }
        if(toggle) cout<<"yes\n";
        else       cout<<"no\n";
    }
    return 0;
}
