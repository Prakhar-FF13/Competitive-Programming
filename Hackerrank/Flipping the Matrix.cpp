#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int m=2*n;
	int arr[m][m];
	for(int i=0;i<m;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
			
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int s1=arr[i][j];
			int s2=arr[i][m-1-j];
			int s3=arr[m-1-i][j];
			int s4=arr[m-1-i][m-j-1];
			sum+=max(max(s1,s2),max(s3,s4));
		}
	}
	cout<<sum<<endl;
	return 0;
}
