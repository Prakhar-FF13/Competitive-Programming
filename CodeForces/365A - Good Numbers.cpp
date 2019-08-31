#include<bits/stdc++.h>
using namespace std;
bool Good(int x, int k){
    set<int> s;
    while(x){
        int r = x%10;
        x /= 10;
        if(r <= k)
            s.insert(r);
    }
    if(s.size() == k+1){
        return true;
    }
    else
        return false;
}
int main(){
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i = 0; i  < n ; i++){
        int x;
        cin>>x;
        if(Good(x, k)) cnt++;
    }
    cout<<cnt;
    return 0;
}
