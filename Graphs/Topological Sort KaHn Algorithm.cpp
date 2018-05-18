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

vi g[10000];
ll cnt;
int n,e,u,v;
vi indegree(10000);
vi topsort;
void calindegree(){
	indegree.assign(n,0);

	rep(i,0,n){
		for(int j = 0; j < (int)g[i].size() ; j++)
			indegree[g[i][j]]++;
	}
}

bool topologicalsortKahn(){
	calindegree();
	rep(i,0,n)
		cout<<indegree[i];
	priority_queue<int,vi,greater<int> > q;
	rep(i,0,n)
		if(indegree[i] == 0)
			q.push(i);
	
	cnt = 0;
	while(!q.empty()){
		int curr = q.top();
		q.pop();
		cnt++;
		topsort.pb(curr);
		rep(j,0,(int)g[curr].size()){
			if( (--indegree[g[curr][j]]) == 0 )
				q.push(g[curr][j]);
		}
	}
	if(cnt != n)
		return false;
	else
		return true;
}
int main()
{
	cin>>n;
	cin>>e;
	rep(i,0,e){
		cin>>u>>v;
		g[u].pb(v);
	}

	if(topologicalsortKahn())
		rep(i,0,(int)topsort.size())
			cout<<topsort[i]<<" ";
	else
		cout<<"Graph contains a cycle \n";
	
	return 0;
}
