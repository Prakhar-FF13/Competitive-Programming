#include <iostream>
using namespace std;

int MaxSubArray(int *arr,int size)
{
	int maxend=0,maxsofar=0;
	for(int i=0;i<size;i++)
	{
		maxend+=arr[i];
		if(maxend < 0)
			maxend=0;
		else if(maxsofar<maxend)
			maxsofar=maxend;
	}
	return maxsofar;
}

int main()
{
	int n;
	cout<<"\n  Enter size of the array : ";
	cin>>n;
	int arr[n];
	cout<<"\n  Enter elements in the array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int maxsum=MaxSubArray(arr,n);
	cout<<"\n  Largest Continous sum in the array : "<<maxsum<<endl;
	return 0;
}
