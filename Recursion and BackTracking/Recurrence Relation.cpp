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

/*
	Compute the nth term of recurrence relation -> f(i) = 2f(i-1) + 3f(i-2) + 5
*/
/* Code formultiplying two matrices */
vector<vector<ll> > multiply(vector<vector<ll> > A, vector<vector<ll> > B){
	vector<vector<ll> > C(3, vector<ll>(3));
	rep(i,0,3)
		rep(j,0,3)
			rep(k,0,3)
				C[i][j] = (((A[i][k] * B[k][j]) % MOD) + C[i][j]) % MOD;
				
	return C;
}
/* Code for calculating matrix power */
vector<vector<ll> > power(vector<vector<ll> > mat, ll p){
	if(p == 1)
		return mat;
	else if(p & 1)
		return multiply(mat, power(mat, p-1));
	else{
		vector<vector<ll> > X = power(mat, p/2);
		return multiply(X, X);
	}
}
/* Code computing nth term of the sequence */
ll compute(ll n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	//Transformation matrix ->
	vector<vector<ll> > T(3, vector<ll>(3));
	//Initialize Transformation matrix.
	rep(i,0,3){
		rep(j,0,3)
			if(i < 2){
				if(j == i+1)
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
			else
				T[i][j] = 0;
	}
	T[1][0] = 3, T[1][1] = 2, T[2][2] = 1;
	
	vector<ll> F(3);
	F[0] = 0;
	F[1] = 1;
	F[2] = 5;
	
	T = power(T, n-1);
	ll ans = 0;
	rep(i,0,3)
		ans += (T[1][i] * F[i]) % MOD;
		
	return ans;
}

int main(){
	cout<<"Enter the value of n : ";
	ll d;
	cin>>d;
	cout<<compute(d)<<"\n";
}
