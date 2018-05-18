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
class UnionFind{
	private:
		vi rank;
		vi p;
	public:
		UnionFind(int n){
			rep(i,0,n){
				rank.pb(1);
				p.pb(i);
			}
		}
		int getSet(int x){
			while(x != p[x])
				x = p[x];
			return x;
		}
		bool isSame(int x, int y){
			return getSet(x) == getSet(y);			
		}
		void make(int x, int y){
			if(!isSame(x, y)){
				int u = getSet(x);
				int v = getSet(y);
				if(rank[u] > rank[v])
					p[v] = u;
				else
					p[u] = v;
				
				if(rank[u] == rank[v])
					rank[v]++;
			}
		}
};
int main()
{
	//RW()
	int m,n,u,v,w;
	ll mst_cost, total;
	while(cin>>m>>n){
		if(m == 0)
			break;
		UnionFind UF(m+5);
		vector<pair<int, pii> > EdgeList;
		mst_cost = 0;
		total = 0;
		rep(i,0,n){
			cin>>u>>v>>w;
			total += w;
			EdgeList.pb(mp(w, mp(u,v)));
		} 	
		sort(EdgeList.begin(), EdgeList.end());
		rep(i,0,n){
			pair<int, pii> curr = EdgeList[i];
			if(!UF.isSame(curr.second.first, curr.second.second)){
				mst_cost += curr.first;
				UF.make(curr.second.first, curr.second.second);
			}
		}
		cout<<total - mst_cost<<"\n";
	}
	return 0;
}
