#include <iostream>
using namespace std;

int memo[100][100]={0};

int getMin(int a,int b)
{
	return a < b ? a : b;
}

int MinPathCost(int cost[100][100],int m,int n)
{
	if(memo[m][n]!=0)
		return memo[m][n];
		
	if(m==0 && n==0)
		memo[m][n]=cost[0][0];
	else if(m==0)
		memo[m][n]=MinPathCost(cost,m,n-1)+cost[m][n];
	else if(n==0)
		memo[m][n]=MinPathCost(cost,m-1,n)+cost[m][n];
	else
	{
		int x=MinPathCost(cost,m-1,n);
		int y=MinPathCost(cost,m,n-1);
		memo[m][n]=getMin(x,y)+cost[m][n];
	}
	return memo[m][n];
}

int main()
{
	int cost[100][100];
	int m,n;
	cout<<"\n  Enter number of rows in the cost matrix : ";
	cin>>m;
	cout<<"\n  Enter number of columns in the cost matrix : ";
	cin>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"  Enter the cost of using "<<i<<" and "<<j<<" cell : ";
			cin>>cost[i][j];
		}
	}
	
	cout<<"\n  Cost matrix is : \n";
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<cost[i][j];
		}
		cout<<endl;
	}
	
	cout<<"\n  Minimum cost of travelling from starting cell to last cell in the bottom right is : "<<MinPathCost(cost,m-1,n-1);
	cout<<endl;
	return 0;
}
