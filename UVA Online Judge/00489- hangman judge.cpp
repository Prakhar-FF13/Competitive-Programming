#include <bits/stdc++.h>
using namespace std;

int main()
{
	/*freopen("read.txt","r",stdin);
	freopen("write.txt","w",stdout);*/
	int hash[30];
	string given,guess;
	int round;
	while(1)
	{
		cin>>round;
		if(round==-1)
			break;
		
		memset(hash,-1,sizeof(hash));
		cin>>given;
		cin>>guess;
		int losecon=7;
		int curlose=0;
		int win=0;
		int dis=0;
		for(int i=0;i<given.length();i++)
		{
			if(hash[given[i]-97]==-1){
				hash[given[i]-97]=1;
				dis++;
			}
		}
		for(int i=0;i<guess.length();i++){
			if(hash[(int)guess[i]-97]==1){
				hash[(int)guess[i]-97]=-2;
				win++;
			}
			else if(hash[(int)guess[i]-97]==-1){
				hash[(int)guess[i]-97]=-2;
				curlose++;
			}
			if(win==dis){
				cout<<"Round ";
				cout<<round<<endl;
				cout<<"You win.\n";
				break;
			}
			else if(curlose==losecon){
				cout<<"Round ";
				cout<<round<<endl;
				cout<<"You lose.\n";
				break;
			}
		}
		if(win!=dis && curlose!=losecon){
		cout<<"Round ";
		cout<<round<<endl;
		cout<<"You chickened out.\n";
	}
	}
	return 0;
}
