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

char g[105][105];
int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int n;
void floodfill(int r, int c, char c1, char c2){
	if(r<0 || r>=n || c<0 || c>=n)
		return;
	else if(g[r][c] != c1 && g[r][c] != c2)
		return;
	else{
		g[r][c] = '.';
		rep(i,0,4){
			floodfill(r + dr[i], c + dc[i], c1, c2);
		}
	}
}
int main()
{
	//RW()
	int cas=1,ans;
	tt(){
		cin>>n;
		rep(i,0,n)
			rep(j,0,n)
				cin>>g[i][j];
		ans = 0;
		rep(i,0,n)
			rep(j,0,n)
				if(g[i][j] == 'x'){
					ans += 1;
					floodfill(i, j, 'x', '@');
				}
					
		cout<<"Case "<<cas++<<": "<<ans<<"\n";
	}
	return 0;
}
