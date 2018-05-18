#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int x[8]={-1,-1,-1,0,0,1,1,1};
int y[8]={-1,0,1,-1,1,-1,0,1};

class StringMatch
{
	private:
		int k;
		int ms;
		int ss;
		char mat[5][5];
		char *str;
		int endi,endj;
	public:
		StringMatch(int m)
		{
			k=0;
			ms=5;
			ss=m;
			str=new char[m];
		}
		
		bool Check(int p,int q)
		{
			if(p>=0 && p<ms && q>=0 && q<ms)
			{
				for(int i=0;i<8;i++)
				{
					if(StrCheck(p+x[i],q+y[i]))
					{ 
						if(k == (ss))
						{
							endi=p+x[i];
							endj=q+y[i];
							return true;
						}
						if(Check(p+x[i],q+y[i]))
							return true;
						else
						{
							k--;
							return false;
						}
					}
				}
			}
			
			else
				return false;
		}
		
		bool StrCheck(int p,int q)
		{
			if(p>=0 && p<ms && q<ms && q>=0)
				if(mat[p][q]==str[k])
				{
					k++;
					return true;
				}
		
			return false;
		}
		
		void Initialize()
		{
			cout<<"\n  Enter matrix Pattern : ";
			for(int i=0;i<ms;i++)
				for(int j=0;j<ms;j++)
					cin>>mat[i][j];
			Display();
			cout<<"\n  Enter string : ";		
			for(int i=0;i<ss;i++)
				cin>>str[i];
		}
		
		bool Find()
		{
			for(int i=0;i<ms;i++)
			{
				for(int j=0;j<ms;j++)
				{
					if(StrCheck(i,j))
					{
						if((Check(i,j)))
						{
							cout<<"\n  String pattern found , Pattern starts at "<<i<<" "<<j<<" ends at "<<endi<<" "<<endj<<"\n\n";
							return true;
						}
					}
					k=0;
				}
			}
			return false;
		}
		
		void Display()
		{
			for(int i=0;i<ms;i++)
			{
				for(int j=0;j<ms;j++)
				{
					cout<<mat[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		
};

int main()
{
	int m;
	cout<<"\n  Enter patter size : ";
	cin>>m;
	StringMatch S(m);
	if(m>25)
		cout<<"\n  Pattern's size is longer than matrix size !!!!!! ";
	else
	{
		S.Initialize();
		if(!S.Find())
			cout<<"\n  String not found ";
	}
				
	getch();
	return 0;
}
