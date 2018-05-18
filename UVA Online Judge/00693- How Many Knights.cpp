#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("read.txt","r",stdin);
	//freopen("write.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m,n!=0 || m!=0)
	{
		if(n==0 || m==0)
			cout<<0<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
		else if(n==1)
			cout<<m<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
		else if(m==1)
			cout<<n<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
		else if( m == 2 || n == 2)
		{
			int solution = ( max(m,n) / 4 ) * 4;

			if( max(m,n) % 4 == 1)
			{
				solution+=2;
			}
			else if( max(m,n) % 4 > 1)
			{
				solution+=4;
			}
			cout<<solution<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
		}
		else
		{
			if(n%2!=0 && m%2!=0)
				cout<<((n*m)/2)+1<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
			else
				cout<<(n*m)/2<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
		}
	}
	return 0;
}
