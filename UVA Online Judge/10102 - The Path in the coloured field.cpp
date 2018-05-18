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
	char arr[100][100];
	int m;
	while(cin>>m){
		vector<pair<int, int> > ones,threes;
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
				if(arr[i][j] == '1')
					ones.push_back(make_pair(i,j));
				if(arr[i][j] == '3')
					threes.pb(mp(i,j));
			}

		int ans = -1;
		for(int i = 0; i<ones.size();i++){
			int partans = (int)(1e9);
			for(int j=0;j<threes.size();j++)
				partans = min(partans, abs(ones[i].first - threes[j].first) + abs(ones[i].second - threes[j].second));
				
			ans = max(ans, partans);
		}
		cout<<ans<<"\n";
	}
	return 0;
}

