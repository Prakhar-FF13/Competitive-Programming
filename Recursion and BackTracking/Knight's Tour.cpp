#include <iostream>
using namespace std;

int moves[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

class KnightsTour
{
	private:
		int board[100][100];
		int n;
		int k;		
	public:
		KnightsTour(int size)
		{
			k=2;
			n=size;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					board[i][j]=0;
		}
		
		bool ValidMove(int i,int j)
		{
			if(i<n && j<n && i>=0 && j>=0)
			{
				if(board[i][j]==0)
				{
					return true;
				}
			}
			return false;
		}
		
		bool Knightconfiguration(int i,int j)
		{
			if(k==n*n+1)
				return true;
			
			for(int q=0;q<8;q++)
			{
				if(ValidMove(i+moves[q][0],j+moves[q][1]))
				{
					board[i+moves[q][0]][j+moves[q][1]]=k;
					k=k+1;
					if(Knightconfiguration(i+moves[q][0],j+moves[q][1])==true)
						return true;
					else
					{
						board[i+moves[q][0]][j+moves[q][1]]=0;
						k=k-1;
					}
				}
			}
			return false;
		}
		
		void Display()
		{
			for(int i=0;i<n;i++)
			{
				cout<<" ";
				for(int j=0;j<n;j++)
					cout<<" "<<board[i][j];
				cout<<"\n";
			}		
		}
		
		void Assign(int i,int j)
		{
			board[i][j]=1;
		}
};


int main()
{
	int n,x,y;
	cout<<"\n What is your boards size : ";
	cin>>n;
	KnightsTour K(n);
	cout<<"\n Enter beginning position of knight (x,y) : ";
	cin>>x>>y;
	K.Assign(x,y);
	K.Knightconfiguration(x,y);
	K.Display();
	return 0;
}
