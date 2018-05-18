#include <iostream>
using namespace std;

int main()
{
	long int i,n,h=1,k=0,t;
	cin>>t;
	long int arr[t];
	while(t)
	{
		h=1;
		cin>>n;
		long int c=0;
		while(c<n)
		{
			if(c%2==0)
				h=h*2;
			else
				h=h+1;
				
			c++;
		}
		t--;
		arr[k++]=h;
	}
	for(int i=0;arr[i];i++)
		cout<<arr[i]<<endl;
		
	return 0;
}
