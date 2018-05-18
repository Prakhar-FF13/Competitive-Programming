/*
This code is correct it was accepted on UVAOJ Dev C++ doesnt run dont know why 
*/


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
int main()
{
	//fsi
	//RW()
	int a,b,c;
	int dice[(int)(1e6+5)];
	vii stend;
	tt()
	{
		cin>>a>>b>>c;
		int ans[(int)(1e6+5)];
		rep(i,0,(int)(1e6+4))
			ans[i]=1;
		
		rep(i,0,b)
		{
			int x,y;
			cin>>x>>y;
			stend.pb(mp(x,y));
		}
		rep(i,1,c+1)
			cin>>dice[i];
		bool flag=false;
		int q=1;
		rep(i,1,c+1)
		{
			if(q==a+1)
				q=1;
			if(flag==false)
			{
				ans[q]+=dice[i];
				rep(k,0,stend.size())
				{
					if(ans[q]==stend[k].first)
					{
						ans[q]=stend[k].second;
						break;
					}
				}
			}
			if(ans[q]>=100)
			{
				flag=true;
				ans[q]=100;
			}
			q++;
		}
		rep(i,1,a+1)
			cout<<"Position of player "<<i<<" is "<<ans[i]<<".\n";
		stend.clear();
	}
	return 0;
}
