#include <iostream>
#include <algorithm>
using namespace std;
class nQueens
{
	private:
		int noOfSolutions;
		int noOfQueens;
		int *queensInRow;
	public:
		nQueens(int queens)
		{
			noOfQueens=queens;
			queensInRow=new int[queens];
			noOfSolutions=0;
		}
		bool check(int k,int i)														//k represents row,i represents the column, of the current queen which is to be placed.
		{
			for(int j=0;j<=k;j++)
			{
				if(queensInRow[j]==i || abs(queensInRow[j]-i)==abs(j-k))			//queensinrow contains the column no at which the queen is placed in each row.
					return false;													//if the queen is present new queen cannot beplaced there so we return false.
			}
			return true;
		}
		void printconfiguration()
		{
			noOfSolutions++;
			for(int j=0;j<noOfQueens;j++)
				cout<<"row : "<<j+1<<" column : "<<queensInRow[j]+1<<"\n";
		}
		void queenconfiguration(int k)
		{
			for(int i=0;i<noOfQueens;i++)											//k->represents the row, loop is used to go through each column in earh row.
			{
				if(check(k,i))														//checking if the queen can be placed or not.
				{
					queensInRow[k]=i;												
					if(k==noOfQueens-1)												//All queens are placed.
						printconfiguration();
					else
						queenconfiguration(k+1);									//moving forward to place next queen if first is placed.
				}
			}
		}
		int nQueensolcount()
		{
			return noOfSolutions;
		}
		
};


int main()
{
	int n;
	cout<<"Enter number of Queens : ";
	cin>>n;
	nQueens Q(n);
	Q.queenconfiguration(0);
	cout<<"\n";
	cout<<Q.nQueensolcount();
	return 0;
}
