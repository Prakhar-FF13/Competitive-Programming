#include <iostream>
using namespace std;

int Adj[100][100];

void DFS(int start,int size)
{
	int top=-1,cur;
	int visited[size]={0};
	visited[start]=1;
	int stack[size];
	stack[++top]=start;
	while(top!=-1)
	{
		cur=stack[top--];
		if(cur<=-1 || cur>=size)
			break;
		else
			cout<<(char)(cur+65)<<" -> ";
		
		for(int i=0;i<size;i++)
		{
			if(visited[i]==0 && Adj[cur][i]==1)
			{
				stack[++top]=i;
				visited[i]=1;
			}
		}
	}
}

int main()
{
	int size;
	cout<<"\nEnter the size of adjacency matrix : ";
	cin>>size;
	cout<<"\nEnter adjacency matrix : \n";
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			cin>>Adj[i][j];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<Adj[i][j]<<" ";
		}
		cout<<endl;
	}
	DFS(0,size);
	return 0;
}
