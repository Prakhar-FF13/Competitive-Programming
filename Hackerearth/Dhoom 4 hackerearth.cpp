#include <iostream>
#include <queue>
#define F(i,a,b) 	for(i=a;i<b;i++)
typedef long long int lli; 
using namespace std;

int main()
{
	int i;
	lli n,ownkey,reqkey;
	cin>>ownkey>>reqkey;
	cin>>n;
	lli ans[100005]={-1};
	lli arr[n];
	F(i,0,n)
		cin>>arr[i];
		
	queue<lli> Q;
	Q.push(ownkey);
	ans[ownkey]=0;
	while(!Q.empty())
	{
		int p=Q.front();
		Q.pop();
		if(p==reqkey)
			break;
		int j;
		F(j,0,n)
		{
			int to=arr[i];
			to*=p;
			to%=100000;
			if(ans[to]==-1)
			{
				ans[to]=ans[p]+1;
				Q.push(to);
			}
			
		}
	}
	cout<<ans[reqkey]<<endl;
	return 0;
}

