#include <iostream>
using namespace std;
 int main()
 {
 	string a,b;
 	int p;
 	cin>>p;
 	while(p--)
 	{
 		cin>>a;
		cin>>b;
		int count=0;
		int ar[26]={0};
		int br[26]={0};
		for(int i=0;i<a.length();i++)
			ar[a[i]-97]++;
		for(int i=0;i<b.length();i++)
			br[b[i]-97]++;
			
		for(int i=0;i<26;i++)
		{
			if(ar[i]>0 && br[i]>0)
			{
				cout<<"YES";
				count=1;
				break;
			}
		}	
		if(count==0)
			cout<<"NO";
	}
	return 0;
 }
