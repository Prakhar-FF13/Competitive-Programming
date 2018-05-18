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
#define eps (int)(-1e5)

int p,q,r,s,t,u;

double f(double x){
	return (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + (u);
}
void Solveit(double a, double b){
	double x = a;
	double y = b;
	double ans = 1000.0;
	if(f(x) * f(y) > 0){
		cout<<"No solution\n";
		return;
	}
	rep(i,0,50){
		double mid = (x + y)/2.0;
		ans = mid;
		if(f(x) * f(mid) <= 0){
			y = mid;
		}
		else
		{
			x = mid;
		}
	}
	printf("%.4lf\n",ans);
}
int main()
{
	while(cin>>p>>q>>r>>s>>t>>u){
		Solveit(0.0000, 1.0000);
	}
	return 0;
}
