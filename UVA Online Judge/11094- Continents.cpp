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
int m,n,ans,ans2;
char g[25][25];
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
int floodfill(int r,int c, char c1){
	if(r<0 || r>=m || c<0 || c>=n)
		return 0;
	else if(g[r][c] != c1)
		return 0;
	else{
		ans2 += 1;
		int t1,t2;
		g[r][c] = '.';
		rep(i,0,4){
			t1 = r + dr[i];
			if(dc[i] == 1)
				t2 = (c + dc[i]) % n;
			else if(dc[i] == -1)
				t2 = (c + dc[i] >=0) ? c + dc[i] : n-1;
			else
				t2 = c + dc[i];
				
			floodfill(t1,t2,c1); 
		}
		return ans2;
	}
}
int main()
{
	//RW()
	int l,k;
	char c1;
	while(cin>>m>>n){
		rep(i,0,m)
			rep(j,0,n)
				cin>>g[i][j];
		
		cin>>l>>k;
		c1 = g[l][k];
		floodfill(l, k, c1);
		ans = 0;
		rep(i,0,m)
			rep(j,0,n){
				ans2 = 0;
				ans = max(ans, floodfill(i, j,c1));
			}
		
		/*rep(i,0,m){
			rep(j,0,n)
				cout<<g[i][j];		
				
			cout<<"\n";
		}*/
		cout<<ans<<"\n";
	}
	return 0;
}
