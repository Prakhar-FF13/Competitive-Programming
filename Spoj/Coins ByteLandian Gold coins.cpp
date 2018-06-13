#include <iostream>
#include <map>
using namespace std;
map<long long,long long> a;
long long rec(long long x)
{
	if(x==0)
		return 0;
	long long c=a[x];
	if(c==0)
	{
		long long c=x-x%12;
		long long d=max(x,rec(x/2)+rec(x/3)+rec(x/4));
		a[x]=d;
	}
	return a[x];
}
int main()
{
	long long n;
	
	while(cin>>n)
	{
		cout<<rec(n)<<endl;
	}
	return 0;
}
