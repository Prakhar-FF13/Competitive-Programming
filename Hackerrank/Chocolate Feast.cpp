#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,c,m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>c;
		cin>>m;
		int count=0;
		count+=n/c;
		int count2=count;
		while(1)
		{
			if(count2<m)
				break;
			else if(count2==m)
			{
				count++;
				count2=0;
				count2++;
			}
			else
			{
				count2=count2-m;
				count++;
				count2++;	
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
