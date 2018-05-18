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

int compare(pll a,pll b){
	return a.second < b.second;
}
int main()
{
	//RW()
	ll num;
	while(cin>>num){
		vll xy;
		rep(i,num+1,(2*num+1)){
			ll y = i;
			ll x = (num * y)/(y - num);
			if(x >= y && (x*y)/(x+y) == num){
				xy.pb(mp(x,y));
			}
		}
		sort(xy.begin(),xy.end(),compare);
		cout<<xy.size()<<"\n";
		for(ll i = 0; i < xy.size(); i++){
			printf("1/%d = 1/%d + 1/%d\n",num, xy[i].first, xy[i].second);
		}
	}
	return 0;
}
