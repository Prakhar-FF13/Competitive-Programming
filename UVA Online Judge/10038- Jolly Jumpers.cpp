#include <bits/stdc++.h>
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
#define all(v)	v.begin(),v.end()

int main()
{
	//fsi
	//RW()
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ht[n+5];
		rep(i,0,n+5)
			ht[i]=0;
		int arr[n+5];
		int cnt=0;
		rep(i,0,n)
			cin>>arr[i];
			
		rep(i,1,n)
		{
			int x=abs(arr[i]-arr[i-1]);
			if(x<=n-1 && ht[x]==0)
			{
				ht[x]=1;
				cnt++;
			}
		}
		if(cnt==n-1)
			cout<<"Jolly\n";
		else
			cout<<"Not jolly\n";
	}
}
