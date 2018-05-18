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
		
	int count=0;
	
	for(int i=0;i<=n-2;i++)
	{  
        if(arr[i]%2!=0)
        {
            arr[i]++;
            arr[i+1]++;
            count+=2;
        }
    }
    if(arr[n-1]%2==0)
        cout<<count<<endl;
    else
        cout<<"NO";
    
	return 0;
}
