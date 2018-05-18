#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int count=0;
	int i=0;
	while(i!=n-1)
	{
		if(i-1 == n-1)
			break;
		i=i+2;
		count++;
		if(i < n && i !=n-1)
			if(arr[i]==1)
			{
				i=i-2;
				i=i+1;
			}
			
	}
	cout<<count;
	return 0;
}
