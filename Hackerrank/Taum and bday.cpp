#include <iostream>
using namespace std;

int main()
{
	long int T,B,W,X,Y,Z;
	cin>>T;
	while(T--)
	{
		cin>>B>>W;
		cin>>X>>Y>>Z;
		if(X!=Y)
		{
			if(X+Z < Y)
				cout<<(X*B)+((X+Z)*W)<<endl;
			else if(Y+Z < X)
				cout<<(Y*W)+((Y+Z)*B)<<endl;
			else
				cout<<(X*B)+(Y*W)<<endl;
		}
		else
			cout<<(X*B)+(Y*W)<<endl;
	}
	return 0;
}
