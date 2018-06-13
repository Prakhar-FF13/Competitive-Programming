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

vi pre(vector<int> prime){
	bool temp[40000];
	for(int i=0;i<40000;i++)
		temp[i]=true;
	for(int i=2;i<40000;i++){
		if(temp[i]==true)
		for(int j=i+i;j<40000;j+=i){
			temp[j]=false;
		}
	}
	for(int i=2;i<40000;i++)
		if(temp[i]==true){
			prime.pb(i);
		}
			
	return prime;
}
int main()
{
	
	vector<int> prime;
	prime=pre(prime);
	int n,m;
	tt()
	{
		cin>>m>>n;
		assert(m<=n);
		for(int i=m;i<=n;i++){
			if(i==1)
				continue;
			bool flag=true;
			for(int j=0;j<prime.size();j++){
				if(i%prime[j]==0 && i!=prime[j])
				{
					flag=false;
					break;
				}
			}
			if(flag==true)
				cout<<i<<endl;
		}
		cout<<"\n";
	}
	return 0;
}
