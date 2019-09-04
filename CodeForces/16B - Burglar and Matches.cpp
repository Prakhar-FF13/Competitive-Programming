#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>m>>n;
    vector<pair<int, int> > conts(n);
    for(int i = 0 ; i < n ; i++){
        int a,b;
        cin>>a>>b;
        conts[i] = make_pair(b, a);
    }
    long long ans = 0;
    sort(conts.rbegin(), conts.rend());
    for(int i = 0 ; i < conts.size() ;){
        int boxes = conts[i].second;
        int matches = conts[i].first;
        if(boxes <= m){
            ans += boxes * matches;
            m -= boxes;
        }else{
            ans += m * matches;
            break;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
