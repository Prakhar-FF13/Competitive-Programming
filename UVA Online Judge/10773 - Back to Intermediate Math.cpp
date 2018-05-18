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

int main()
{
	//RW()
	fsi
	int c = 1;
	tt(){
		double d,v,u;
		cin>>d>>v>>u;
		double d1=0,d2=0;
		if(u != 0)
			d1 = d/u;
		if(v < u && u != 0 && v != 0)
			d2 =  d/(u * sqrt(1 - (v/u * v/u)));
		double p = abs(d1-d2);
		if(v < u && u != 0 && v != 0)
			printf("Case %d: %.3f\n",c++,p);
		else
			printf("Case %d: can't determine\n",c++);
	}
	return 0;
}
