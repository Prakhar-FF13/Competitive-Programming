#include <iostream>
using namespace std;

int main()
{
	int n,k,cost=0,b;
	cin>>n>>k;
	int c[n];
	for(int i=0;i<n;i++)
		cin>>c[i];
	cin>>b;
	for(int i=0;i<n;i++)
	{
		if(i==k)
			continue;
		cost+=c[i];
	}
	if(b==cost/2)
		cout<<"Bon Appetit"<<endl;
	if(b!=cost/2)
		cout<<b-(cost/2);
		
	return 0;
}
