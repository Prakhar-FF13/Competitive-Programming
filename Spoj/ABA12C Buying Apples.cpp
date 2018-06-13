#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;
int64 price[102],n,k,temp;
int64 dp[1000][1000];
#define rep(a,b)	for(int i=a;i<=b;i++)

int64 minCost(int64 index,int64 sum)
{
	if(sum==0)
	{
		return 0;
	}
	
	if(sum<0 || index>temp)
	{
		return 1000;
	}
	
	if(dp[index][sum]!=-1)
	{
		return dp[index][sum];
	}
	else
	{
		int64 minc=1000;
		for(int i=index;i<=temp;i++)
		{
			if(price[i]!=-1)
			{
				minc=min(minc,min(minCost(i+1,sum),minCost(i,sum-i)+price[i]));
			}
		}
		dp[index][sum]=minc;
		return minc;
	}
}

int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		memset(dp,-1,sizeof(dp));
		int n,k;
		cin>>n>>k;
		temp=k;
		for(int i=1;i<=k;i++)
		{
			cin>>price[i];
		}
			
		int64 cost=minCost(1,temp);
		if(cost>=1000)
			cout<<-1<<endl;
		else
			cout<<cost<<endl;
	}
	return 0;
}
