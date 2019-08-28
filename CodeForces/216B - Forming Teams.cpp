#include<bits/stdc++.h>
using namespace std;
vector<int> g[105];
int color[105];

void biPartitie(int s){
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0 ; i < g[u].size() ; i++){
            int v = g[u][i];
            if(color[v] == -1){
                q.push(v);
                color[v] = 1 - color[u];
            }
            else if(color[v] == color[u]){
                color[v] = -2;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i =0 ; i <  105; i++)
        color[i] = -1;

    for(int i = 1; i <= n ; i++){
        if(color[i] == -1) biPartitie(i);
    }

    int cnt=0;
    for(int i = 1; i <= n ; i++)
        if(color[i] == -2) cnt++;

    if((n - cnt) & 1) cnt++;
    cout<<cnt;
    return 0;
}
