#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
#include<sstream>
#include<vector>
 
using namespace std;
 
int N;
char a, b, c;
string line;
stringstream ss;
vector<char> elements;
vector<vector<char> > adj;
map<char, bool> vis;
 
bool valid(char e) {
    for(int i = 0; i < adj[e].size(); i++)
        if(vis[adj[e][i]])
            return false;
    return true;
}
 
bool dfs(string path) {
    if(path.length() == elements.size()) {
        printf("%c", path[0]);
        for(int i = 1; i < path.length(); i++)
            printf(" %c", path[i]);
        printf("\n");
        return true;
    }
    bool ans = false;
    for(int i = 0; i < elements.size(); i++) {
        if(!vis[elements[i]]) {
            if(valid(elements[i])) {
                vis[elements[i]] = true;
                ans = dfs(path + elements[i]) || ans;
                vis[elements[i]] = false;
            }
        }
    }
    return ans;
}
 
int main() {
    scanf("%d\n\n", &N);
 
    for(int T = 0;; T++) {
        if(T > 0) printf("\n");
 
        getline(cin, line);
        ss.clear();
        ss.str(line);
        elements.clear();
        while(ss >> a)
            elements.push_back(a);
        sort(elements.begin(), elements.end());
 
        getline(cin, line);
        ss.clear();
        ss.str(line);
        adj.clear();
        adj.resize(256);
        while(ss >> a >> b >> c)
            adj[a].push_back(c);
 
        if(!dfs(""))
            printf("NO\n");
        if(!getline(cin, line)) break;
    }
}
