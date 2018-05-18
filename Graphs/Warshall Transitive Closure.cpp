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
ll g[500][500];
ll n,e,x,y,q;
void Warshall(){
	ms(g,0,sizeof(g));
	rep(k,0,n)
		rep(i,0,n)
			rep(j,0,n)
				g[i][j] |= (g[i][k] & g[k][j]); 
}
int main()
{
	// Matrix Repreentation of a set.
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter total number of edges : ";
	cin>>e;
	rep(i,0,e){
		cin>>x>>y;
		g[x][y] = g[y][x] = 1;
	}
	Warshall();
	cout<<"Enter number of queries : ";
	cin>>q;
	while(q--){
		cout<<"Enter the vertices : ";
		cin>>x>>y;
		if(g[x][y])
			cout<<"Vertices are connected \n";
		else
			cout<<"Vertices are not connected \n";
	}
}
