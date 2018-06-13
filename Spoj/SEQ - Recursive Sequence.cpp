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
#define MOD 	1000000000
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

vector<ll> b,c;
int k;
vector<vector<ll> > multiply(vector<vector<ll> > a, vector<vector<ll> > b){
	vector<vector<ll> > C(k, vector<ll>(k));
	
	rep(i,0,k){
		rep(j,0,k)
			rep(q,0,k){
				C[i][j] = (((a[i][q] * b[q][j])%MOD) + C[i][j])%MOD;
			}
	}
	return C;
}

vector<vector<ll> > power(vector<vector<ll> > a, ll p){
	if(p == 1)
		return a;
		
	if(p & 1)
		return multiply(a, power(a, p-1));
	
	vector<vector<ll> > x = power(a, p/2);
	return multiply(x, x);
}

ll compute(ll n){
	if(n == 0)
		return 0;
	if(n <= k)
		return b[n-1];
	
	vector<ll> f(k);
	rep(i,0,k)
		f[i] = b[i];
		
	vector<vector<ll> > T(k, vector<ll>(k));
	rep(i,0,k){
		rep(j,0,k){
			if(i < k-1){
				if(j == i + 1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
					
				continue;
			}
			T[i][j] = c[k - j - 1];
		}
	}
	
	T = power(T, n-1);
	
	ll ans = 0;
	
	rep(i,0,k){
		ans = ( ans + (T[0][i] * f[i]) % MOD ) % MOD;
	}
	return ans;
}
int main()
{
	fsi
	tt(){
		cin>>k;
		b.clear();
		c.clear();
		rep(i,0,k){
			ll x;
			cin>>x;
			b.pb(x);
		}
		rep(i,0,k){
			ll x;
			cin>>x;
			c.pb(x);
		}
		ll n;
		cin>>n;
		cout<<compute(n)<<"\n";
	}
	return 0;
}
