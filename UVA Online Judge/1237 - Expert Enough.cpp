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
	fsi
	tt()
	{
		int D;
		scanf("%d",&D);
		vector< pair< string, pair<int,int> > > m;
		rep(i,0,D){
			string str;
			int l,h;
			cin>>str>>l>>h;
			m.pb(mp(str,mp(l,h)));
		}
		int Q;
		cin>>Q;
		while(Q--){
			int cnt=0,pos=-1;
			int p;
			cin>>p;
			rep(i,0,D){
				if(m[i].second.first<=p && m[i].second.second>=p){
					cnt++;
					pos=i;
				}
				if(cnt>1)
					break;
			}
			if(cnt>1 || pos==-1)
				cout<<"UNDETERMINED\n";
			else
				cout<<m[pos].first<<"\n";
		}
		if(t)
			cout<<"\n";
	}
	return 0;
}
