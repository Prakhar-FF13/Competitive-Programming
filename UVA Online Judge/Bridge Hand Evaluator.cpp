#include <bits/stdc++.h>
using namespace std;

int main()
{
	char hand[45];
	//freopen("read.txt","r",stdin);
	//freopen("write.txt","w",stdout);
	while(cin.getline(hand,45))
	{
		bool pres[4][4];
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				pres[i][j]=false;
				
		int suits[4]={0};
		int total=0;
		for(int i=0;hand[i];i+=3)
		{
			//Rule 1 A-4 K-3 Q-2 J-1
			if(hand[i]=='A')						
			{
				total+=4;
				if(hand[i+1]=='S')
				{
					suits[0]++;
					pres[0][0]=true;
				}
				else if(hand[i+1]=='H')
				{
					suits[1]++;
					pres[1][0]=true;
				}
				else if(hand[i+1]=='D')
				{
					suits[2]++;
					pres[2][0]=true;
				}
				else
				{
					suits[3]++;
					pres[3][0]=true;
				}
			}
			else if(hand[i]=='K')
			{
				total+=3;
				if(hand[i+1]=='S')
				{
					suits[0]++;
					pres[0][1]=true;
				}
				else if(hand[i+1]=='H')
				{
					suits[1]++;
					pres[1][1]=true;
				}
				else if(hand[i+1]=='D')
				{
					suits[2]++;
					pres[2][1]=true;
				}
				else
				{
					suits[3]++;
					pres[3][1]=true;
				}
			}
			else if(hand[i]=='Q')
			{
				total+=2;
				if(hand[i+1]=='S')
				{
					suits[0]++;
					pres[0][2]=true;
				}
				else if(hand[i+1]=='H')
				{
					suits[1]++;
					pres[1][2]=true;
				}
				else if(hand[i+1]=='D')
				{
					suits[2]++;
					pres[2][2]=true;
				}
				else
				{
					suits[3]++;
					pres[3][2]=true;
				}
			}
			else if(hand[i]=='J')
			{
				total+=1;
				if(hand[i+1]=='S')
				{
					suits[0]++;
					pres[0][3]=true;
				}
				else if(hand[i+1]=='H')
				{
					suits[1]++;
					pres[1][3]=true;
				}
				else if(hand[i+1]=='D')
				{
					suits[2]++;
					pres[2][3]=true;
				}
				else
				{
					suits[3]++;
					pres[3][3]=true;
				}
			}
			else
			{
				if(hand[i+1]=='S')
					suits[0]++;
				else if(hand[i+1]=='H')
					suits[1]++;
				else if(hand[i+1]=='D')
					suits[2]++;
				else
					suits[3]++;
			}
		}
		//cout<<"R1 total -> "<<total<<endl;
		//Rule 2,3,4
		for(int i=0;i<4;i++)
		{
			if(pres[i][1]==true && suits[i]==1)
				total-=1;
			if(pres[i][2]==true && suits[i]<=2)
				total-=1;
			if(pres[i][3]==true && suits[i]<=3)
				total-=1;
		}
		//cout<<"R234 total -> "<<total<<endl;
		//suit stop checking !!!
		if(total>=16 && (pres[0][0] || (pres[0][1] && suits[0]>=2) || (pres[0][2] && suits[0]>=3)) && (pres[1][0] || (pres[1][1] && suits[1]>=2) || (pres[1][2] && suits[1]>=3)) && (pres[2][0] || (pres[2][1] && suits[2]>=2) || (pres[2][2] && suits[2]>=3)) && (pres[3][0] || (pres[3][1] && suits[3]>=2) || (pres[3][2] && suits[3]>=3)))
		{
			cout<<"BID NO-TRUMP\n";
		}
		else
		{
			//rule 5,6,7
			for(int i=0;i<4;i++)
			{
				if(suits[i]==2)
					total+=1;
				if(suits[i]<=1)
					total+=2;	
			}
			//cout<<"R567 total -> "<<total<<endl;
			if(total<14)
			{
				cout<<"PASS\n";
			}
			else 
			{
				int maxe=(int)1e6,el=-1;
				for(int i=0;i<4;i++)
				{
					//cout<<suits[i]<<endl;
					if(suits[i]==el)
					{
						maxe=min(i,maxe);
					}
					else if(suits[i] > el)
					{
						el=suits[i];
						maxe=i;
					}
				}
				if(maxe==0)
					cout<<"BID S\n";
				else if(maxe==1)
					cout<<"BID H\n";
				else if(maxe==2)
					cout<<"BID D\n";
				else
					cout<<"BID C\n";
			}
		}
	}
	return 0;
}
