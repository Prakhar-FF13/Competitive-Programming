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
priority_queue< pll, vll, greater<pll> > q;
vll g[100005];
ll m,n,a,b,l,z;
vector<ll> mst, c(100005);
ll sum = 0;
int taken[100005];
void process(ll u){
	taken[u] = 1;
	rep(i,0,(int)g[u].size()){
		pll v = g[u][i];
		if(!taken[v.first]){
			q.push(mp(v.second, v.first));
		}
	}
}
int main(){
	cin>>n>>m;
	rep(i,0,m){
		cin>>a>>b>>l;
		g[a].pb(mp(b,l));
		g[b].pb(mp(a,l));
	}
	cin>>z;
	rep(i,0,z)
		cin>>c[i];
	sort(c.begin(), c.begin() + z);
	ms(taken, 0 , sizeof(taken));
	process(1);
	mst.pb(1);
	while(!q.empty()){
		pii curr = q.top();
		q.pop();
		if(!taken[curr.second]){
			process(curr.second);
			mst.pb(curr.first);
			sum += curr.first;
		}
	}	
	int k = mst.size() - 1;
	int f = 0;
	sort(mst.begin(), mst.end());
	while(k >= 0 && f < z){
		if(mst[k] > c[f]){
			sum -= mst[k];
			sum += c[f];
			k--, f++;
		}
		else
			break;
	}
	cout<<sum<<"\n";
	return 0;
}
