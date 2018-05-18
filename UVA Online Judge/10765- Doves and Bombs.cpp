#include<bits/stdc++.h>
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

const int maxn = 10010;
   
   class Vertex {
   public:
       int id;
       vector<int> adjList;
   };
   
   class ArticulationPoint {
   public:
       int id, point;
   
       ArticulationPoint(int _id, int _p): id(_id), point(_p) {}
   
       bool operator<(const ArticulationPoint &p) const {
           if (this->point < p.point) return true;
           else if (this->point == p.point && this->id > p.id) return true;
           return false;
       }
   
      bool operator>(const ArticulationPoint &p) const {
           if (this->point > p.point) return true;
           else if (this->point == p.point && this->id < p.id) return true;
           return false;
       }
   };
   
   bool readFile();
   void articulationPoint();
   void solve();
   
   vector<Vertex> vlist;
   vector<ArticulationPoint> result;
   int dfs_low[maxn], dfs_num[maxn], fa[maxn], deltaInc[maxn];
  int n, m, dfsCnt, nChild, root;
  
  int main()
  {
      while (readFile()) {
          solve();
      }
      return 0;
  }
  
  bool readFile() {
      cin >> n >> m;
      if (n == 0 && m == 0) return false;
      vlist.assign(n, Vertex());
  
      int u, v;
      cin >> u >> v;
      while (u != -1 && v != -1) {
	      vlist[u].adjList.push_back(v);
          vlist[v].adjList.push_back(u);
  
          cin >> u >> v;
      }
  
      return true;
  }
  
  void articulationPoint(int u) {
      dfs_num[u] = dfs_low[u] = ++dfsCnt;
  
      for (int i = 0; i < (int)vlist[u].adjList.size(); i++) {
          int v = vlist[u].adjList[i];
          if (dfs_num[v] == 0) {
              fa[v] = u;
              if (u == root) nChild++;
  
              articulationPoint(v);
              if (dfs_low[v] >= dfs_num[u])
                  deltaInc[u]++;
  
              dfs_low[u] = min(dfs_low[u], dfs_low[v]);
          } else if (v != fa[u])
              dfs_low[u] = min(dfs_low[u], dfs_num[v]);
      }
  }
  
  void solve() {
      result.clear();
      int cc = 0;
      for (int i = 0; i < n; i++) {
          dfs_low[i] = dfs_num[i] = 0;
          deltaInc[i] = 0;
          fa[i] = i;
      }
  
      for (int i = 0; i < n; i++) {
          if (dfs_num[i] == 0) {
              dfsCnt = 0;
              cc++;
              root = i;
              nChild = 0;
              articulationPoint(i);
              deltaInc[i] = nChild - 1;
          }
      }
  
      for (int i = 0; i < n; i++) {
          result.push_back(ArticulationPoint(i, cc + deltaInc[i]));
      }
  
      sort(result.begin(), result.end(), greater<ArticulationPoint>());
  
      for (int i = 0; i < m; i++)
          cout << result[i].id << " " << result[i].point << endl;
      cout << endl;
  }
