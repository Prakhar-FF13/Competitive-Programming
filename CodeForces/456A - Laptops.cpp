#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > lappy(n);
    for(int i = 0; i  < n ; i++){
        int a,b;
        cin>>a>>b;
        lappy[i] = make_pair(a, b);
    }
    sort(lappy.begin(), lappy.end());
    for(int i = 0 ; i  < lappy.size() - 1 ; i++){
        pair<int,int> a = lappy[i];
        pair<int,int> b = lappy[i+1];
        if(a.second > b.second){
            cout<<"Happy Alex";
            return 0;
        }
    }
    cout<<"Poor Alex";
    return 0;
}
