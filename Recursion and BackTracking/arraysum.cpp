#include <iostream>
using namespace std;

int sumarr(int arr[])
{
	if(!(*arr))
		return 0;
	else
	{
		return *arr+sumarr(arr+1);
	}
}

int main()
{
	int *arr;
	int n;
	cout<<"Enter the size of the integer array : ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter array : ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<sumarr(arr);
	return 0;
}
