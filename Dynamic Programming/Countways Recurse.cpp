#include <iostream>
using namespace std;

int countWays(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	return countWays(n-1)+countWays(n-2);
}

int main()
{
	int n;
	cout<<"\n  Enter the lenght : ";
	cin>>n;
	cout<<"\n  Number of ways to fill the block with 2*1 tiles is : "<<countWays(n);
	return 0;
	
}
