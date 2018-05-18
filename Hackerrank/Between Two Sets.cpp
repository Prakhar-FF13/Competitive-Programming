#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,count=0;
	cin>>n>>m;
	
	int arr[n],arr2[m];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	for(int i=0;i<m;i++)
		cin>>arr2[i];
		
	sort(arr,arr+n);
	sort(arr2,arr2+m);
	for(int i=arr[n-1];i<=arr2[0];i++)
	{
		int j;
		for(j=0;j<n;j++)
			if(i%arr[j]!=0)
				break;
				
		if(j!=n)
			continue;
		
		for(j=0;j<m;j++)
			if(arr2[j]%i!=0)
				break;
				
		if(j!=m)
			continue;
			
		count++;
		
	}
	
	cout<<count;
	return 0;
}
