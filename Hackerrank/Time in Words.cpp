#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char str[30][20]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine" };

int main()
{
	int H,M;
	cin>>H;
	cin>>M;
	if(M==0)
		cout<<str[H]<<" o' clock"<<endl;
	else if(M==1)
		cout<<str[1]<<" minute past "<<str[H]<<endl;
	else if(M==15)
		cout<<"quarter past "<<str[H]<<endl;
	else if(M==30)
		cout<<"half past "<<str[H]<<endl;
	else if(M<30)
		cout<<str[M]<<" minutes past "<<str[H]<<endl;
	else if(M==45)
		cout<<"quarter to "<<str[H+1]<<endl;
	else 
		cout<<str[60-M]<<" minutes to "<<str[H+1]<<endl;
		
	return 0;
			
}
