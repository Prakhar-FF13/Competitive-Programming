#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[4]={0,0,0,0};
    vector<int> vi[4];
    for(int i = 0 ; i  < n ; i++){
        int ti;
        cin>>ti;
        arr[ti]++;
        vi[ti].push_back(i+1);
    }
    int m=1000000;
    for(int i = 1; i < 4; i++)
        m = min(m, arr[i]);
    cout<<m<<"\n";
    for(int i = 0 ; i < m; i++){
        cout<<vi[1][i]<<" "<<vi[2][i]<<" "<<vi[3][i]<<"\n";
    }
    return 0;
}
