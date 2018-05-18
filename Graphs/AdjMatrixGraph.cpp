#include <iostream>
#include <cstdlib>
using namespace std;

class Graph
{
	private:
		int vertices;
		int **Adm;
	public:
		Graph(int n)
		{
			vertices=n;
			Adm=(int **)malloc(sizeof(int *) * (vertices));
			for(int i=0;i<vertices;i++)
				for(int j=0;j<vertices;j++)
					Adm[i]=(int *)malloc(sizeof(int)*vertices);
			for(int i=0;i<vertices;i++)
				for(int j=0;j<vertices;j++)
					Adm[i][j]=0;
		}
		void Insert()
		{
			int m,u,v;
			cout<<"\n  Enter number of edges you want to enter in graph : ";
			cin>>m;
			for(int i=0;i<m;i++)
			{
				cout<<"\n  Enter coordinates of "<<i<<" edge : ";
				cin>>u;
				cin>>v;
				Adm[u][v]=1;
				Adm[v][u]=1;
			}
		}
		void Display()
		{
			for(int i=0;i<vertices;i++)
			{
				cout<<"\n  ";
				for(int j=0;j<vertices;j++)
				{
					cout<<Adm[i][j]<<" ";
				}
			}
			cout<<"\n";
		}
		
		void ResetGraph()
		{
			cout<<"\n  Resetting graph : ";
			for(int i=0;i<vertices;i++)
				for(int j=0;j<vertices;j++)
					Adm[i][j]=0;
					
			cout<<"  Graph reset completed ";
		}

		void Menu()
		{
			int choice;
			do
			{
				cout<<"\n  ******Main Menu******   ";
				cout<<"\n1.Enter edges in a graph ";
				cout<<"\n2.Display Graph ";
				cout<<"\n3.Reset Graph ";
				cout<<"\n4.Exit ";
				cout<<"\n  Enter your choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1: Insert();
							break;
					case 2: Display();
							break;
					case 3: ResetGraph();
							break;
					case 4: cout<<"\n  Exiting !!! ";
							break;
					default: cout<<"\n  Wrong choice : ";
							break;
				}
			}
			while(choice!=4);
		}
};

int main()
{
	int n;
	cout<<"\n  Enter number of vertices to be in your graph : ";
	cin>>n;
	Graph G(n);
	G.Menu();
	return 0;
}

