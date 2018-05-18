#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int carr[101]={0,0};
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
		carr[arr[i]]++;
	int big=carr[0];
	for(int i=0;i<101;i++)
		if(carr[i]>big)
			big=carr[i];
			
	cout<<n-big;
	
	return 0;
}
