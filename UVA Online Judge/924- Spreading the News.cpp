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
vi g[5000];
bool visited[5000];
int dist[5000];
int boom[5000];
int n, e, v, max_boom_day, max_boom;
void bfs(int u){
	ms(visited,false,sizeof(visited));
	ms(dist,-1,sizeof(dist));
	ms(boom,0,sizeof(boom));
	max_boom = max_boom_day = -1;
	queue<int> q;
	q.push(u);
	dist[u] = 1;
	visited[u] = true;
	while(!q.empty()){
		int curr = q.front(); q.pop();
		for(int i = 0; i< (int)g[curr].size(); i++){
			if(!visited[g[curr][i]]){
				dist[g[curr][i]] = dist[curr] + 1;
				boom[dist[curr]]++;
				q.push(g[curr][i]);
				visited[g[curr][i]] = true; 
			}
		}
		if(boom[dist[curr]] > max_boom){
			max_boom = boom[dist[curr]];
			max_boom_day = dist[curr];
		}
	}
}
int main()
{
	//RW()
	cin>>n;
	char ch;
	rep(i,0,n){
		cin>>e;
		rep(j,0,e){
			cin>>v;
			g[i].pb(v);
		}
	}
	tt(){
		cin>>v;
		bfs(v);
		if(max_boom)
			cout<<max_boom<<" "<<max_boom_day<<"\n";
		else
			cout<<"0\n";
	}
	return 0;
}
