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
	tt(){
		int n;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		ll sum=0;
		rep(i,1,n){
			rep(j,0,i){
				if(arr[j] <= arr[i])
					sum+=1;
			}
		}
		cout<<sum<<"\n";
	}
}
