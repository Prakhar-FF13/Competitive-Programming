#include <iostream>
#include <vector>
#include <queue>
int n,m;
int visited[1002][1002];
int graph[1002][1002];
using namespace std;

int findans(int x,int y)
{
	queue<int> qx;
	queue<int> qy;
	visited[x][y]=1;
	qx.push(x);
	qy.push(y);
	int counter=0;
	
	while(!qx.empty())
	{
		int cx=qx.front();
		int cy=qy.front();
		qx.pop();
		qy.pop();
		for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=1;j++)
			{
				if((i+cx>=1) && (i+cx<=n) && (j+cy>=1) && (j+cy<=m))
				{
					if(visited[i+cx][j+cy]==0 && graph[i+cx][j+cy]==1)
					{
						counter++;
						qx.push(i+cx);
						qy.push(j+cy);
						visited[i+cx][j+cy]=1;
					}
				}
			}
		}
	}
	
	return counter;
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>graph[i][j];
		
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				visited[i][j]=0;

						
		int ans=0;
		int counter=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;i++)
			{
				if(graph[i][j]==1)
				if(visited[i][j]==0)
				{
					counter++;
					int temp=findans(i,j);
					if(temp>ans)
					{
						ans=temp;
					}
				}
			}
		}
		
		cout<<counter<<" "<<ans<<endl;
	}
}
