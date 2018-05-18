#include <iostream>
using namespace std;

int Adj[100][100];

void BFS(int start,int size)
{
	int rear=-1,front=-1,cur;
	int q[size*size],visited[size]={0};
	q[++rear]=start;
	visited[start]=1;
	
	while(rear!=front)
	{
		cur=q[++front];
		if(cur>=size)
			break;
		else
			cout<<(char)(cur+65)<<" -> ";
			
		for(int i=0;i<size;i++)
		{
			if(visited[i]==0 && Adj[cur][i]==1)
			{
				q[++rear]=i;
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
	cout<<"\nEnter adjacency matrix of size "<<size<<" * "<<size<<"\n";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cin>>Adj[i][j];
		}
	}
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<Adj[i][j]<<" ";
		}
		cout<<endl;
	}	
	BFS(0,size);
	return 0;
}
