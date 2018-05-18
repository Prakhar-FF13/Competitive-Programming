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

int main()
{
	//RW()
	int f,r;
	while(1){
		cin>>f;
		if(f==0)
			break;
		cin>>r;
		int ft[f],rt[r];
		for(int i=0;i<f;i++)
			cin>>ft[i];
		for(int i=0;i<r;i++)
			cin>>rt[i];
		vector<double> w;
		for(int i=0;i<f;i++)
			for(int j=0;j<r;j++)
				w.pb(((double)rt[j])/ft[i]);
				
		sort(w.begin(),w.end());
		vector<double> spd;
		double ans=-(1e7);
		for(int i=1;i<w.size();i++)
			spd.pb(((double)w[i])/w[i-1]);
		for(int i=0;i<spd.size();i++)
			if(spd[i] > ans)
				ans=spd[i];
		printf("%.2f\n",ans);
	}	
	return 0;
}
