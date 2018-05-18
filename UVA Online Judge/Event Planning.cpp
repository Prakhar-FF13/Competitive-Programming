#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,b,h,w;
	while(cin>>n>>b>>h>>w)
	{
		int minc=(int)1e7;
		for(int i=0;i<h;i++)
		{
			int x;
			cin>>x;
			int temp=(int)1e7;
			for(int j=0;j<w;j++)
			{
				int y;
				cin>>y;
				if(y<n)
				{
					continue;
				}
				else
				{
					temp=n*x;
				}
			}
			minc=min(temp,minc);
		}
		if(minc==(int)1e7 || minc > b)
			cout<<"stay home"<<endl;
		else
			cout<<minc<<endl;
	}
	return 0;
}
