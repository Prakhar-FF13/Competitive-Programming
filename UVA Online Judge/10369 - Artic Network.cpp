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
ll s,p;
vll coords;
vdll EdgeList;
vector<double> reqPaths;
class UnionFind{
    int n;
    vector<int> rank,parent;
    public:
        UnionFind(int n){
            this->n = n+5;
            rep(i,0,this->n){
                parent.pb(i);
                rank.pb(0);
            }
        }
        int getParent(int x){
            if(parent[x] == x)
                return x;
            return parent[x] = getParent(parent[x]);
        }
        void Union(int x,int y){
            int px = getParent(x);
            int py = getParent(y);
            if(px == py)    return;
            int rx = rank[px];
            int ry = rank[py];
            if(rx < ry){
                parent[px] = py;
            }else{
                parent[py] = px;
                if(rx == ry)
                    rx++;
            }
        }
};

double getDistance(pll a, pll b){
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    ll SqAdd = (dx*dx + dy*dy)*1.0;
    return sqrt(SqAdd);
}
void generateEdgeList(){
    EdgeList.clear();
    rep(i, 0, p){
        pll u = coords[i];
        rep(j , i+1, p){
            pll v = coords[j];
            EdgeList.pb(mp(getDistance(u, v), mp(i, j)));
        }
    }
    sort(EdgeList.begin(), EdgeList.end());
}
void MST(){
    UnionFind UF(p+3);
    reqPaths.clear();
    ll e = 0;
    ll reqE = p-1;
    for(int i = 0 ; i < EdgeList.size() ; i++){
        if(e == reqE)   break;
        pdii edge = EdgeList[i];
        ll u = edge.second.first;
        ll v = edge.second.second;
        if(UF.getParent(u) != UF.getParent(v)){
            e++;
            reqPaths.pb(edge.first);
            UF.Union(u, v);
        }
    }
}

double getAns(){
    return reqPaths[p-s-1];
}

int main(){
    RW()
    tt(){
        cin>>s>>p;
        coords.clear();
        rep(i, 0, p){
            ll x,y;
            cin>>x>>y;
            coords.pb(mp(x,y));
        }
        generateEdgeList();
        MST();
        printf("%.2lf\n", getAns());
    }
    return 0;
}
