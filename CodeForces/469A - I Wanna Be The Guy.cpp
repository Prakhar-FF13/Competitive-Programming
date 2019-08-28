#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> x;
    int n;
    cin>>n;
    int p;
    cin>>p;
    while(p--){
        int s;
        cin>>s;
        x.insert(s);
    }
    int q;
    cin>>q;
    while(q--){
        int s;
        cin>>s;
        x.insert(s);
    }
    if(x.size() == n)
        cout<<"I become the guy.";
    else
        cout<<"Oh, my keyboard!";
}
