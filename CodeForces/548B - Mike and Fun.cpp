#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) ((x)<<1)
#define R(x) (((x)<<1)+1)
#define umap unordered_map
#define double long double
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef complex<double> point;
template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}
const int maxn = 500 + 10;
bool a[maxn][maxn];
int n, m, q;
int mx[maxn];
inline void calc(int i){
	int cur = 0;
	mx[i] = 0;
	For(j,0,m){
		if(a[i][j])
			cur ++;
		else
			cur = 0;
		smax(mx[i], cur);
	}
}
int main(){
	iOS;
	cin >> n >> m >> q;
	For(i,0,n)
		For(j,0,m)
			cin >> a[i][j];
	For(i,0,n)
		calc(i);
	while(q--){
		int i, j;
		cin >> i >> j;
		-- i, -- j;
		a[i][j] = !a[i][j];
		calc(i);
		int ans = 0;
		For(i,0,n)
			smax(ans, mx[i]);
		cout << ans << '\n';
	}
}