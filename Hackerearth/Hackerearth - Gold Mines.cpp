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

int main(){
	int R,C;
	cin>>R>>C;
	ll mine[R][C];
	rep(i,0,R){
		rep(j,0,C){
			cin>>mine[i][j];
			if( i > 0 ) mine[i][j] += mine[i-1][j];
			if( j > 0 ) mine[i][j] += mine[i][j-1];
			if( i > 0 && j > 0 ) mine[i][j] -= mine[i-1][j-1];
		}
	}
	int Q,x1,x2,y1,y2;
	cin>>Q;
	while(Q--){
		cin>>x1>>y1>>x2>>y2;
		x1--,x2--,y1--,y2--;
		ll sum = mine[x2][y2];
		if(x1 > 0)
			sum -= mine[x1-1][y2];
		if(y1 > 0)
			sum -= mine[x2][y1-1];
		if(x1 > 0 && y1 > 0)
			sum += mine[x1-1][y1-1];
			
		cout<<sum<<"\n";
	}
	return 0;
		
}
