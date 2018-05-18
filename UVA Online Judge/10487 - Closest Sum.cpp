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
	int n;
	int tc=0;
	while(1){
		cin>>n;
		if(n==0)
			break;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		vi sum;
		for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i != j)
						sum.pb(arr[i]+arr[j]);	
			}
		}
		sort(sum.begin(),sum.end());
		/*for(int i = 0; i < sum.size(); i++)
			cout<<"index -> "<<i<<" sum -> "<<sum[i]<<"\n";*/
		int m;
		cin>>m;
		cout<<"Case "<<++tc<<":\n";
		while(m--){
			int query;
			cin>>query;
			int ans1 = (lower_bound(sum.begin(), sum.end(), query)-sum.begin());
			if(ans1-1 >=0)
				if(abs(query-sum[ans1]) >= abs(query - sum[ans1-1]))
					ans1=ans1-1;
			
			cout<<"Closest sum to "<<query<<" is "<<sum[ans1]<<".\n";		
		}
	}
	return 0;
}
