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
typedef vector<pii> vii;
typedef vector<pll> vll;
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


class UnionFind{
    int n;
    int parent[120];
    int rank[120];
    public:
        UnionFind(){}
        UnionFind(int n){
            this->n = n;
            rep(i,0,n+5){
                parent[i] = i;
                rank[i] = 0;
            }
        }
        int find(int x){
            if(parent[x] == x)
                return x;
            int temp = x;
            while(parent[temp] != temp){
                temp = parent[temp];
            }
            return parent[x] = temp;
        }
        void Union(int x, int y){
            int px = find(x), py = find(y);
            if(px == py) return;
            int rx = rank[px], ry = rank[py];
            if(rx < ry){
                parent[px] = py;
            }else{
                parent[py] = px;
                if(rx == ry)
                    rx++;
            }
        }
};

vector<int> taken_edges;
int MST(vector<pair<int, pii> > &EdgeList, int n, int notToIncludeEdge){
    UnionFind UF(n+3);
    if(notToIncludeEdge == -1)
        taken_edges.clear();
    int edges = 0;
    int sum = 0;
    rep(i, 0, EdgeList.size()){
        if(edges == n-1)  break;
        if(i == notToIncludeEdge)   continue;
        pair<int, pii > edge = EdgeList[i];
        int a = edge.second.first;
        int b = edge.second.second;
        if(UF.find(a) != UF.find(b)){
            edges++;
            if(notToIncludeEdge == -1)
                taken_edges.pb(i);
            sum += edge.first;
            UF.Union(a, b);
        }
    }
    if(edges != n-1)
        sum = 1e9;
    return sum;
}

int main(){
    //RW()
    tt(){
        int n,m;
        cin>>n>>m;
        vector<pair<int, pii > > EdgeList(m);
        rep(i, 0, m){
            int a,b,c;
            cin>>a>>b>>c;
            EdgeList[i] = mp( c, mp(a,b) );
        }
        sort(EdgeList.begin(), EdgeList.end());
        int s1 = MST(EdgeList, n, -1);
        int s2 = 1e9;
        rep(i,0,taken_edges.size()){
            s2 = min(s2, MST(EdgeList, n, taken_edges[i]));
        }
        cout<<s1<<" "<<s2<<endl;
    }
    return 0;
}
