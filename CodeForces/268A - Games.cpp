#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i = 0 ; i < n ;  i++){
        int x,y;
        cin>>x>>y;
        arr[i] = make_pair(x, y);
    }

    int cnt=0;
    for(int i = 0 ; i  < n ; i++) // ith is visiting.
        for(int j = 0 ; j <  n ; j++){ // jth is host.
            if(i == j) continue;
            int awayGuest = arr[i].second;
            int homeHome = arr[j].first;
            if(homeHome == awayGuest)
                cnt++;
        }
    cout<<cnt;
    return 0;
}
