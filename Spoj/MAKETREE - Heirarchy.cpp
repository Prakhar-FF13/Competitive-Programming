#include<bits/stdc++.h>
using namespace std;
vector<int> g[100005];
vector<int> topsort;
int visited[100005];
int boss[100005];
void dfs(int s){
    visited[s] = 1;
    for(int i = 0 ; i < g[s].size() ; i++){
        int v = g[s][i];
        if(visited[v] == -1)
            dfs(v);
    }
    topsort.push_back(s);
}

int main(){

    int n,k;
    cin>>n>>k;
    memset(visited, -1, sizeof(visited));
    for(int i = 1 ; i <= k ;i++){
        int w;
        cin>>w;
        while(w--){
            int x;
            cin>>x;
            g[i].push_back(x);
        }
    }
    for(int i = 1; i <= n ; i++){
        if(visited[i] == -1)
            dfs(i);
    }
    reverse(topsort.begin(), topsort.end());
    memset(boss, -1, sizeof(boss));
    int prev = 0;
    for(int i = 0; i < topsort.size() ; i++){
        boss[topsort[i]] = prev;
        prev = topsort[i];
    }
    for(int i = 1; i <= n ; i++)
        cout<<boss[i]<<"\n";
    return 0;
}
