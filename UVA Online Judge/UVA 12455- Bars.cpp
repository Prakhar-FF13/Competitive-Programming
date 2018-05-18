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
	int n,p,arr[25];
	tt()
	{
		cin>>n;
		cin>>p;
		rep(i,0,p)
			cin>>arr[i];
		int sum=0;
		if(n==0){
			cout<<"YES\n";
			continue;
		}
		rep(i,0,(1<<p)){
			sum=0;
			rep(j,0,p){
				if(i & (1<<j))
					sum+=arr[j];
			}
			if(sum==n)
				break;
		}
		if(sum==n){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}
