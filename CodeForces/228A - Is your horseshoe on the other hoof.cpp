#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,w,z;
    cin>>x>>w>>y>>z;
    set<int> colors;
    colors.insert(x), colors.insert(w);
    colors.insert(y), colors.insert(z);
    cout<<4 - colors.size();
    return 0;
}
