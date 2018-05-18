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

ll x,y;
float avg;
ll g[105][105];
void FloydWarshall(){
	rep(k,1,101)
		rep(i,1,101)
			rep(j,1,101)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
void AvgPathLength(){
	avg = 0.0;
	float sum = 0.0;
	int combi = 0;
	rep(i,1,101)
		rep(j,1,101)
			if(i != j && g[i][j] != (ll)(1e4)){
				sum += g[i][j];
				combi++;
			}
	avg = sum/(float)combi;
}
int main(){
	//RW()
	fsi
	ll cas = 1;
	while(1){
		cin>>x>>y;
		if( x == 0 && y == 0)
			break;
		else{
			rep(i,0,101)
				rep(j,0,101)
					g[i][j] = (ll)(1e4);
			g[x][y] = 1;
			while(1){
				cin>>x>>y;
				if(x == 0 && y == 0)
					break;
				g[x][y] = 1;
			}
			FloydWarshall();
			AvgPathLength();
			cout<<"Case "<<cas++<<": average length between pages = "<<setprecision(3)<<fixed<<avg<<" clicks\n";
			//printf("%.3f",avg);
			//cout<<" clicks\n";
		}
	}
	return 0;
	
}
