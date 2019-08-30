#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    stack<char> x;
    int cnt = 0;
    for(int i = 0; i  < n ; i++){
        if(x.size() && x.top() != str[i]){
            x.pop();
            cnt += 2;
        }else{
            x.push(str[i]);
        }
    }
    cout<<n - cnt;
    return 0;
}
