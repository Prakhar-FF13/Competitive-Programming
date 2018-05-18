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
ll g[500][500], p[500][500];
ll n,e,x,y,w,q;
void FloydWarshall(){
	rep(i,0,n)
		rep(j,0,n)
			p[i][j] = i;
	
	rep(k,0,n)
		rep(i,0,n)
			rep(j,0,n)
				if(g[i][k] + g[k][j] < g[i][j]){
					g[i][j] = g[i][k] + g[k][j];
					p[i][j] = p[k][j];
				}
}
void printPath(int i, int j){
	if(i != j)	printPath(i, p[i][j]);
	cout<<j<<"->";
}
int main()
{
	cout<<"Enter number of vertices : ";
	cin>>n;
	cout<<"Enter total number of edges : ";
	cin>>e;
	cout<<"Enter u,v and w : \n";
	ms(g,MOD,sizeof(g));
	rep(i,0,e){
		cin>>x>>y>>w;
		g[x][y] = w;
	}
	FloydWarshall();
	cout<<"Enter total number of queries : ";
	cin>>q;
	while(q--){
		cout<<"Enter vertices between which you want to get the minimum distance : ";
		cin>>x>>y;
		cout<<" Path = ";
		printPath(x,y);
		cout<<" Cost = "<<g[x][y]<<"\n";
	}
	return 0;
}
