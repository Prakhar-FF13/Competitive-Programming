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
int n,m;
map<pii, pii> parent;
set<pii> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool fnd;

void displayPair(pii a){
    cout<<"First: "<<a.first<<"   Second: "<<a.second<<"  ";
}

void dfs(pii src, char color, vector<vector<char> > &mat){
    visited.insert(src);
    rep(i, 0, 4){
        int new_i = src.first + dx[i];
        int new_j = src.second + dy[i];
        if(new_i >=0 && new_i < n && new_j >= 0 && new_j < m){
            pii x = mp(new_i, new_j);
            if(visited.find(x) == visited.end() && mat[new_i][new_j] == color){
                parent[x] = src;
                dfs(x, color, mat);
            }else if(mat[new_i][new_j] == color){
                pii parent_src = parent[src];
                if(parent_src != x && parent_src != mp(-1,-1)){
                    //displayPair(src);displayPair(x);displayPair(parent_src)<<endl;
                    fnd = true;
                }
            }
        }
    }
}

int main(){
    cin>>n>>m;
    vector<vector<char>> mat(n, vector<char>(m));
    rep(i,0,n)
        rep(j,0,m){
            cin>>mat[i][j];
            parent[mp(i,j)] = mp(-1,-1);
        }
    fnd = false;
    rep(i,0,n)
        rep(j,0,m){
            if(visited.find(mp(i,j)) == visited.end() && fnd == false){
                dfs(mp(i,j), mat[i][j], mat);
            }
        }
    if(fnd) cout<<"Yes";
    else    cout<<"No";
    return 0;
}
