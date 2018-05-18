#include <iostream>
#include <cstring>
using namespace std;

bool BSearch(int *arr,int low,int high,int data)
{
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(data==arr[mid])
			return true;
		else if(data > arr[mid])
			return BSearch(arr,mid+1,high,data);
		else 
			return BSearch(arr,low,mid-1,data);
	}    
	return false;
}

int main()
{
	int n,d;
	cin>>n;
	cin>>d;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int count=0;
	for(int i=0;i<=n-d;i++)
	{
		if(BSearch(arr,0,n-1,arr[i]+d)==true)
			if(BSearch(arr,0,n-1,arr[i]+d+d)==true)
				count++;
	}
	
	cout<<count<<endl;
	return 0;
}
