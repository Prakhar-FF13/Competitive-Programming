#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int min=1002;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j] && abs(i-j)<min)
				min=abs(i-j);
		}
	}
	if(min==1002)
		min=-1;

	cout<<min<<endl;
	return 0;
	
}
