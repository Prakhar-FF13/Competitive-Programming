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
class UF{
	private:
		vi parent;
		vi rank;
	public:
		UF(int n){
			rep(i,0,n){
				parent.pb(i);
				rank.pb(1);
			}
		}
		int getParent(int x){
			while(x != parent[x])
				x = parent[x];
			return x;
		}	
		bool isSameSet(int p,int q){
			return getParent(p) == getParent(q);
		}
		void makeset(int p, int q){
			if(!isSameSet(p,q)){
				int x = getParent(p);
				int y = getParent(q);
				if(rank[x] > rank[y])
					parent[y] = x;
				else
					parent[x] = y;
					
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
};

int main()
{
	int n,e,u,v,w;
	vector<pair<int, pii> > EdgeList;
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter total number of edges : ";
	cin>>e;
	cout<<"Enter vertices between which edge exists and the weight of that edge : \n";
	rep(i,0,e){
		cin>>u>>v>>w;
		EdgeList.pb(mp(w, mp(u,v)));
	}
	int mst_cost = 0;
	UF Set(n);
	sort(EdgeList.begin(), EdgeList.end());
	rep(i,0,e){
		pair<int, pii> curr = EdgeList[i];
		if(!Set.isSameSet(curr.second.first, curr.second.second)){
			mst_cost += curr.first;
			Set.makeset(curr.second.first, curr.second.second);
		}
	}
	cout<<"Minimum Spanning Tree Cost : ";
	cout<<mst_cost<<"\n";
	return 0;
}
