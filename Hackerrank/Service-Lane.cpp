#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t,car=2,bike=1,truck=3;
	cin>>n>>t;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	while(t--)
	{
		int i,j;
		cin>>i>>j;
		int min=arr[i];
		for(int q=i+1;q<=j;q++)
		{
			if(arr[q]<min)
				min=arr[q];
		}
		cout<<min<<endl;
	}
	return 0;
}
