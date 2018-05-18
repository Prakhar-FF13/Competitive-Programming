#include <iostream>
#include <cstdlib>
using namespace std;

class MaintainOrder
{
	private:
		char *str1,*str2,*ostr;
		int m,n,i;
	public:
		MaintainOrder(int M,int N)
		{
			m=M;
			n=N;
			str1=(char *)malloc(sizeof(char) * m);
			str2=(char *)malloc(sizeof(char) * n);
			ostr=(char *)malloc(sizeof(char) * (m+n+1));
			ostr[m+n]='\0';
			i=0;
		}
		void Initialize()
		{
			cout<<"\n  Enter String 1 : ";
			cin>>str1;
			cout<<"\n  Enter string 2 : ";
			cin>>str2;
		}
		void printstringrec(char *strm,char *strn,int m,int n,int i)
		{
			if(m==0 && n==0)
			{
				cout<<"\n"<<ostr;
			}
			if(m!=0)
			{
				ostr[i]=strm[0];
				printstringrec(strm+1,strn,m-1,n,i+1);
			}
			if(n!=0)
			{
				ostr[i]=strn[0];
				printstringrec(strm,strn+1,m,n-1,i+1);
			}
		}
		void PrintString()
		{
			printstringrec(str1,str2,m,n,i);
		}
};

int main()
{
	int m, n;
	cout<<"\n  Enter size of string 1 : ";
	cin>>m;
	cout<<"\n  Enter size of string 2 : ";
	cin>>n;
	MaintainOrder M(m,n);
	M.Initialize();
	M.PrintString();
	return 0;
}
