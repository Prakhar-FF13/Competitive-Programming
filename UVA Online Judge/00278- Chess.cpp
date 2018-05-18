#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("read.txt","r",stdin);
	//freopen("write.txt","w",stdout);
	int t,n,m,q;
	char c;
	cin>>t;
	while(t--)
	{
		cin>>c>>n>>m;
		switch(c)
		{
			case 'r': cout<<min(m,n)<<endl;
					  break;
			case 'Q': cout<<min(m,n)<<endl;
					  break;
			case 'K':   q=0;
						if(n%2==0)
							q+=n/2;
						else
							q+=(n+1)/2;
							
						if(m%2==0)
							q*=m/2;
						else
							q*=(m+1)/2;
							
					   cout<<q<<endl;
					  break;
			case 'k': if(n%2!=0 && m%2!=0)
						cout<<((n*m)/2)+1<<endl;
					  else
					    cout<<(n*m)/2<<endl;
		}
	}
	return 0;
}
