#include <iostream>
using namespace std;

int main()
{
	cout<<"\n  Enter total number of stations : ";
	int n;
	cin>>n;
	int cost[n][n]={0};
	int mincost[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j>i)
			{
				cout<<"\n  Enter the cost of tavelling from station "<<i+1<<" to station "<<j+1<<" : ";
				cin>>cost[i][j];
			}
		}
	}
	mincost[0]=0;
	mincost[1]=cost[0][1];
	for(int i=2;i<n;i++)
	{
		mincost[i]=cost[0][i];
		for(int j=1;j<i;j++)
		{
			if(mincost[i]>mincost[j]+cost[j][j])
				mincost[i]=mincost[j]+cost[j][i];
		}
	}
	cout<<"\n  The least money to get you to the last station is : "<<mincost[n-1]<<endl;
	return 0;
	
}
