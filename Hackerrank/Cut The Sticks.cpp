#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	while(1)
	{
		int count=0;
		int min=100000;
		for(int i=0;i<n;i++)
		{
			if(arr[i]<min && arr[i]!=0)
				min=arr[i];
		}
				
		for(int i=0;i<n;i++)
		{
			if(arr[i]>0)
			{
				count++;
				arr[i]=arr[i]-min;
			}
		}
			
		if(count==0)
			break;
			
		cout<<count<<endl;
	}
	
	return 0;
}
