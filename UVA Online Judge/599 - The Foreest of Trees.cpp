#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

vector<bool> visited;

void dfs(vector<int> g[26], int x, int &cnt) {
    if (visited[x] == true) return;
    visited[x] = true;
    cnt++;
    rep(i, 0, g[x].size()) {
        if (visited[g[x][i]] == false)
            dfs(g, g[x][i], cnt);
    }
}

int main () {
    RW()
    fsi
    int t;
    scanf("%d", &t);
    while(t--) {
        vector<int> g[26];
        string str;
        while(cin>>str) {
            if (str[0] == '*')  break;
            int a = str[1] - 'A', b = str[3] - 'A';
            g[a].pb(b);
            g[b].pb(a);
        }
        cin>>str;
        vector<int> q;
        for(int i = 0; i < str.length(); i += 2)
            q.pb(str[i]-'A');

        int acorns = 0, trees = 0;
        visited.clear();
        visited.assign(26, false);
        for(auto it = q.begin(); it != q.end(); it++) {
            int x = *it;
            if (!visited[x]) {
                int cnt = 0;
                dfs(g, x, cnt);
                if (cnt == 1)
                    acorns++;
                else
                    trees++;
            }
        }
        cout<<"There are "<<trees<<" tree(s) and "<<acorns<<" acorn(s)."<<endl;
    }
    return 0;
}