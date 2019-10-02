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
int n,m,e;
vii townCoords;
vector<pair<double, pii> > EdgeList;
int edgesConnection[755][755];
class UnionFind{
    int N;
    vector<int> parent;
    vector<int> rank;
    public:
        UnionFind(){}
        UnionFind(int n){
            N = n+5;
            rep(i,0,N){
                parent.pb(i);
                rank.pb(0);
            }
        }
        // find parent of x.
        int find(int x){
            if(parent[x] == x)
                return parent[x];
            else
                return parent[x] = find(parent[x]);
        }
        // union of two groups.
        void Union(int x, int y){
            int px = parent[x];
            int py = parent[y];
            if(px == py)    return;
            int rx = rank[px];
            int ry = rank[py];
            if(rx < ry){
                parent[px] = py;
            }else{
                parent[py] = px;
                if(rx == ry)
                    rank[px]++;
            }
        }
};
UnionFind UF;
double distanceBtwTowns(pii a, pii b){
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    double sumOfSq = dx*dx + dy*dy;
    return sqrt(sumOfSq);
}

void take_input(){
    // take townCoordinates input.
    cin>>n;
    townCoords.clear();
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        townCoords.pb(mp(x,y));
    }

    // input number of existing highways.
    cin>>m;
    EdgeList.clear();
    ms(edgesConnection, 0, sizeof(edgesConnection));
    UF = *(new UnionFind(751));
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        // 0 based indexing.
        a--, b--;
        edgesConnection[a][b] = edgesConnection[b][a] = 1;
        // distance between towns a and b.
        double distance = distanceBtwTowns(townCoords[a], townCoords[b]);
        // insert into edge list this edge.
        EdgeList.pb( mp( distance, mp(a, b) ) );
        UF.Union(a, b);
    }
    e = m; // edges already in MST.
}

void addRemainingEdges(){
    rep(i,0,n)
        rep(j, i+1, n)
            if(edgesConnection[i][j] == 0){
                double dist = distanceBtwTowns(townCoords[i], townCoords[j]);
                EdgeList.pb( mp( dist, mp(i,j) )  );
            }
    sort(EdgeList.begin(), EdgeList.end());
}

void performMST(){
    int takenNewHighways = 0;
    if(e!=n-1)
    rep(i, 0, EdgeList.size()){
        if(e == n-1)    break;

        // take and Edge.
        pair<double, pii > Edge = EdgeList[i];
        int a = Edge.second.first;
        int b = Edge.second.second;

        // check to see whether it was already in MST or not.
        if(edgesConnection[a][b] == 0 && (UF.find(a) != UF.find(b))){
            cout<<a+1<<" "<<b+1<<endl;
            edgesConnection[a][b] = edgesConnection[b][a] = 1;
            e++;
            UF.Union(a, b);
            takenNewHighways++;
        }
    }
    if(takenNewHighways == 0)   cout<<"No new highways need"<<endl;
}

int main(){
    //RW()
    tt(){
        take_input();
        addRemainingEdges();
        performMST();
        if(t)   cout<<endl;
    }
    return 0;
}
