#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> x;
    for(int i = 0; i < n ; i++){
        string q;
        cin>>q;
        x.push_back(q);
    }
    string ans = x[0];
    long long c = 1;
    for(int i = 1 ; i < x.size() ; i++){
        if(x[i] == ans)
            c++;
        else
            c--;
    }
    if(c<0){
        for(int i = 0 ; i < x.size() ; i++)
            if(x[i] != ans){
                ans = x[i];
                break;
            }
    }
    cout<<ans;
    return 0;
}
