#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	char **Mat,**SMat;
	int n,count=0,k;
	cout<<"\n  Enter number of lines : ";
	cin>>n;
	SMat=(char **)malloc(sizeof(char *) * n);
	for(int i=0;i<n;i++)
		SMat[i]=(char *)malloc(sizeof(char) * n);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			SMat[i][j]='O';

	k=n;
	n=2*n-1;
	Mat=(char **)malloc(sizeof(char *) * n);
	
	for(int i=0;i<n;i++)
		Mat[i]=new char[n];
		
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			Mat[i][j]=' ';
			
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if((i+j)%2==0 && j>=i)
				Mat[i][j]='O';
	
	cout<<"\n  From : \n";
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<Mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\n  To : \n";
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<SMat[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(Mat[i][n-1-j]!=SMat[i][j])
				count++;
		}
	}
	cout<<"\n Number of moves needed to turn the isosceles triangle to square : "<<count/2;
	
	return 0;
}
