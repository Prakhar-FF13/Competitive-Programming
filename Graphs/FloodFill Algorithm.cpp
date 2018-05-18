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

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};
char g[1000][1000]; // Adjacency matrix representation of graph.
int n;
int floodfill(int r,int c, char c1, char c2){
	if(r<0 || r>=n || c<0 || c>=0)
		return 0;
	else if(g[r][c] != c1)
		return 0;
	else{
		int ans = 1;
		rep(i,0,8){
			ans += floodfill(r + dr[i], c + dc[i], c1, c2);
		}
		return ans;
	}
}
int main()
{
	int n; // no of vertices.
	cin>>n;
	int e; // no of edges.
	cin>>e;
	rep(i,0,e){
		int u,v;
		cin>>u>>v; // Edge between vertices u and v.
		g[u][v] = '1'; // Assuming Directed graph.
	}
	int x,y; // Coordinates from where floodfill algo should start.
	cin>>x>>y;
	char c1,c2; // Color to replaced c1, color to replace c2.
	cin>>c1;
	cin>>c2;
	floodfill(x, y, c1, c2);
	return 0;
}
