#include <iostream>
using namespace std;

int main()
{
	int cost[100][100];
	int m,n;
	cout<<"\n  Enter number of rows : ";
	cin>>m;
	cout<<"  Enter number of colums : ";
	cin>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"  Enter the cost of using "<<i<<" and "<<j<<" cell : ";
			cin>>cost[i][j];
		}
	}
	
	for(int i=1;i<m;i++)
		cost[i][0]=cost[i-1][0]+cost[i][0];
		
	for(int j=0;j<n;j++)
		cost[0][j]=cost[0][j-1]+cost[0][j];
	
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			cost[i][j]=min(cost[i-1][j],cost[i][j-1])+cost[i][j];
		}
	}
	
	cout<<"\n  Minimum cost of travelling from starting cell to last cell is : "<<cost[m-1][n-1]<<endl;
	return 0;
}
