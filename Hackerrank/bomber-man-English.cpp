#include <iostream>
#include <cstdlib>

using namespace std;

class BomBerMan
{
	private:
		int r,c;
		char **Mat,n,**temp;
	public:
		BomBerMan(int R,int C,char N)
		{
			r=R;
			c=C;
			n=N;
			Mat=(char **)malloc(sizeof(char *)*r);
			temp=(char **)malloc(sizeof(char *)*r);
			for(int i=0;i<r;i++)
				Mat[i]=(char *)malloc(sizeof(char)*c);
			for(int i=0;i<r;i++)
				temp[i]=(char *)malloc(sizeof(char)*c);
			
		}
		void StartingMat()
		{
			cout<<"\n  Entering O means there is a bomb at that place . means that position is empty ";
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
				{
					cout<<"\n  Enter for "<<i<<" "<<j<<" pos : ";
					fflush(stdin);
					cin>>Mat[i][j];
				}
				
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
				{
					if(Mat[i][j]=='O')
						Mat[i][j]='0';
				}
		}
		
		void Equalize()
		{
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					temp[i][j]=Mat[i][j];
		}
		
		void Solve()
		{
			char k='1';
			Equalize();
			while(k<=n)
			{
				Equalize();
				if(atoi(&k)%2==0)
				{
					for(int i=0;i<r;i++)
						for(int j=0;j<c;j++)
						{
							if(Mat[i][j] == '.')
								Mat[i][j]=k;
						}
				}
				
				if(atoi(&k)%3==0)
				{
					for(int i=0;i<r;i++)
					{
						for(int j=0;j<c;j++)
						{
							if(abs( atoi(&k) - atoi(&temp[i][j]) ) % 3 == 0)
							{
								Mat[i][j]='.';
								if(i-1>=0 && i-1<r)
									Mat[i-1][j]='.';
								if(i+1>=0 && i+1<r)
									Mat[i+1][j]='.';
								if(j-1>=0 && j-1<r)
									Mat[i][j-1]='.';
								if(j+1>=0 && j+1<r)
									Mat[i][j+1]='.';
								
							}
						}
					}
				}
				cout<<"\n";
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
					{
						cout<<Mat[i][j]<<" ";
					}
					cout<<"\n";
				}
				k++;
			}
		}
		
		void Display()
		{
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(Mat[i][j]!='.')
						Mat[i][j]='O';
					else
						Mat[i][j]='.';
						
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cout<<Mat[i][j]<<" ";
				}
				cout<<"\n";
			}		
		}
		
};

int main()
{
	int r,c;
	char n;
	cout<<"\n  Enter the rows and column of matrix : ";
	cin>>r>>c;
	cout<<"\n  Enter the time after which you want to see your matrix : ";
	cin>>n;
	BomBerMan B(r,c,n);
	B.Display();
	B.StartingMat();
	B.Solve();
	B.Display();
	return 0;
}
