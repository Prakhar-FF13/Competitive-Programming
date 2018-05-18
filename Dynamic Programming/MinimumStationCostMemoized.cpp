#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;

ll MinCost(int s,int d,ll cost[][100],ll memo[][100])
{
	if(s==d || s==d-1)
		return cost[s][d];
	if(memo[s][d]==0)
	{
		ll temp;
		for(int i=s+1;i<d;i++)
		{
			temp=min(MinCost(s,i,cost,memo)+MinCost(i,d,cost,memo),cost[s][d]);
		}
		memo[s][d]=temp;
		return temp;
	}
	return memo[s][d];
}

int main()
{
	ll n;
	cout<<"\n  Enter total number of stations : ";
	cin>>n;
	ll cost[100][100],memo[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i==j)
				cost[i][j]=0;
			else if(i>j)
				cost[i][j]=-1;
				
			memo[i][j]=0;
		}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<j)
			{
				cout<<"  Enter the cost of travelling from station "<<i+1<<" to "<<j+1<<" : ";
				cin>>cost[i][j];
			}
		}
	}
	
	cout<<"\n  Minimum Cost of travelling from 1st station to the last one is : "<<MinCost(0,n-1,cost,memo);
	
	return 0;
}
