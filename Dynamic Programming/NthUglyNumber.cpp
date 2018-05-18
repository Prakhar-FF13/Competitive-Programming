#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int NthUglyNumber(int n)
{
	int arr[n];
	arr[0]=1;
	int i2=0,i3=0,i5=0;
	int next2=2,next3=3,next5=5;
	int next=1;
	for(int i=1;i<n;i++)
	{
		next=min(next2,next3);
		next=min(next,next5);
		arr[i]=next;
		if(next==next2)
		{
			i2++;
			next2=arr[i2]*2;
		}
		if(next==next3)
		{
			i3++;
			next3=arr[i3]*2;
		}
		if(next==next5)
		{
			i5++;
			next5=arr[i5]*2;
		}
	}
	return next;
}

int main()
{
	int n;
	cout<<"\n  Enter the nth ugly u wish to know : ";
	cin>>n;
	int ugly=NthUglyNumber(n);
	cout<<"\n  Ugly number at position "<<n<<" is "<<ugly<<endl;
	return 0;
}
