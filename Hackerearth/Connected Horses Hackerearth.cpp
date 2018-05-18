#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1004][1004];
#define MOD 1000000007
ll bfs(ll i,ll j)
{
	list<pair<ll,ll> > queue;
	queue.push_back(make_pair(i,j));
	ll count=1;
	a[i][j]=0;
	while(!queue.empty())
	{
		pair<ll,ll> temp=queue.front();
		ll c=temp.first;
		ll v=temp.second;
		queue.pop_front();
		if(a[c+2][v+1])	
		{
			a[c+2][v+1]=0;
			queue.push_back(make_pair(c+2,v+1));
			count++;
		}
		if(a[c+2][v-1])	
		{
			a[c+2][v-1]=0;
			queue.push_back(make_pair(c+2,v-1));
			count++;
		}
		if(a[c+1][v+2])	
		{
			a[c+1][v+2]=0;
			queue.push_back(make_pair(c+1,v+2));
			count++;
		}
		if(a[c+1][v-2])	
		{
			a[c+1][v-2]=0;
			queue.push_back(make_pair(c+1,v-2));
			count++;
		}
		if(a[c-2][v+1])	
		{
			a[c-2][v+1]=0;
			queue.push_back(make_pair(c-2,v+1));
			count++;
		}
		if(a[c-2][v-1])	
		{
			a[c-2][v-1]=0;
			queue.push_back(make_pair(c-2,v-1));
			count++;
		}
		if(a[c-1][v+2])	
		{
			a[c-1][v+2]=0;
			queue.push_back(make_pair(c-1,v+2));
			count++;
		}
		if(a[c-1][v-2])	
		{
			a[c-1][v-2]=0;
			queue.push_back(make_pair(c-1,v-2));
			count++;
		}	
	}
	return count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,m,q;
		cin>>n>>m>>q;
		
		for(ll i=0;i<1004;i++)
		{
			for(ll j=0;j<1004;j++)
			{
				a[i][j]=0;
			}
		}
		while(q--)
		{
			ll x,y;
			cin>>x>>y;
			x++;
			y++;
			a[x][y]=1;
		}
		ll ans=1;
		for(ll i=2;i<n+2;i++)
		{
			for(ll j=2;j<m+2;j++)
			{
				if(a[i][j])
				{
					ll p=bfs(i,j);
					for(ll w=1;w<=p;w++)
					{
						ans=(((ans%MOD)*(w%MOD))+MOD)%MOD;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}