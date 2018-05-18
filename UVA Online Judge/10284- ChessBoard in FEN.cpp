#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b)	for(int i=a;i<b;i++)
char board[12][12];
void Queen(int x,int y)
{
	int tx=x-1,ty=y;
	while(tx>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx--][ty]='x';
	tx=x+1;
	while(tx<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx++][ty]='x';
	tx=x;
	ty=y+1;
	while(ty<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx][ty++]='x';
	ty=y-1;
	while(ty>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx][ty--]='x';
	tx=x-1;
	ty=y-1;
	while(tx>=1 && ty>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx--][ty--]='x';
	tx=x-1,ty=y+1;
	while(tx>=1 && ty<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx--][ty++]='x';
	tx=x+1,ty=y-1;
	while(tx<=8 && ty>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx++][ty--]='x';
	tx=x+1,ty=y+1;
	while(tx<=8 && ty<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx++][ty++]='x';
	
}
void Bishop(int x,int y)
{
	int tx=x-1;
	int ty=y-1;
	while(tx>=1 && ty>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx--][ty--]='x';
	tx=x-1,ty=y+1;
	while(tx>=1 && ty<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx--][ty++]='x';
	tx=x+1,ty=y-1;
	while(tx<=8 && ty>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx++][ty--]='x';
	tx=x+1,ty=y+1;
	while(tx<=8 && ty<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx++][ty++]='x';
}

void Knight(int x,int y)
{
	if(x-2>=1 && y-1>=1 && board[x-2][y-1]==' ')
		board[x-2][y-1]='x';
	if(x-2>=1 && y+1<=8 && board[x-2][y+1]==' ')
		board[x-2][y+1]='x';
	if(x+2<=8 && y-1>=1 && board[x+2][y-1]==' ')
		board[x+2][y-1]='x';
	if(x+2<=8 && y+1<=8 && board[x+2][y+1]==' ')
		board[x+2][y+1]='x';
	if(x-1>=1 && y-2>=1 && board[x-1][y-2]==' ')
		board[x-1][y-2]='x';
	if(x-1>=1 && y+2<=8 && board[x-1][y+2]==' ')
		board[x-1][y+2]='x';
	if(x+1<=8 && y-2>=1 && board[x+1][y-2]==' ')
		board[x+1][y-2]='x';
	if(x+1<=8 && y+2<=8 && board[x+1][y+2]==' ')
		board[x+1][y+2]='x';
}
void Rook(int x,int y)
{
	int tx=x-1,ty=y;
	while(tx>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx--][ty]='x';
	tx=x+1;
	while(tx<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx++][ty]='x';
	tx=x;
	ty=y+1;
	while(ty<=8 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx][ty++]='x';
	ty=y-1;
	while(ty>=1 && (board[tx][ty]==' ' || board[tx][ty]=='x'))
		board[tx][ty--]='x';	
}
void Bpawn(int x,int y)
{
	if(x+1<=8 && y-1>=1 && board[x+1][y-1]==' ')
		board[x+1][y-1]='x';
	if(x+1<=8 && y+1<=8 && board[x+1][y+1]==' ')
		board[x+1][y+1]='x';
}
void Wpawn(int x,int y)
{
	if(x-1>=1 && y-1>=1 && board[x-1][y-1]==' ')
		board[x-1][y-1]='x';
	if(x-1>=1 && y+1<=8 && board[x-1][y+1]==' ')
		board[x-1][y+1]='x';
}
void King(int x,int y)
{
	if(board[x-1][y]==' ')
		board[x-1][y]='x';
	if(board[x+1][y]==' ')
		board[x+1][y]='x';
	if(board[x][y-1]==' ')
		board[x][y-1]='x';
	if(board[x][y+1]==' ')
		board[x][y+1]='x';
	if(board[x-1][y-1]==' ')
		board[x-1][y-1]='x';
	if(board[x-1][y+1]==' ')
		board[x-1][y+1]='x';
	if(board[x+1][y-1]==' ')
		board[x+1][y-1]='x';
	if(board[x+1][y+1]==' ')
		board[x+1][y+1]='x';
}
int main()
{
	/*freopen("read.txt","r",stdin);
	freopen("write.txt","w",stdout);*/
	rep(i,0,12)
		rep(j,0,12)
			board[i][j]=' ';

	string str;
	while(1)
	{
		int row=1,col=1;
		getline(cin,str);
		if(str.length()==0 || str.length()==1)
			break;
		rep(i,0,12)
		rep(j,0,12)
			board[i][j]=' ';
		rep(i,0,str.length())
		{
			if(str[i]=='/')
			{
				row++;
				col=1;
			}
			else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
			{
				board[row][col]=str[i];
				col++;
			}
			else
			{
				col+=(((int)str[i])-48);
			}
		}
		rep(i,1,9)
			rep(j,1,9)
			{
				if(board[i][j]=='q' || board[i][j]=='Q')
					Queen(i,j);
				else if(board[i][j]=='b' || board[i][j]=='B')
					Bishop(i,j);
				else if(board[i][j]=='n' || board[i][j]=='N')
					Knight(i,j);
				else if(board[i][j]=='r' || board[i][j]=='R')
					Rook(i,j);
				else if(board[i][j]=='p')
					Bpawn(i,j);
				else if(board[i][j]=='P')
					Wpawn(i,j);
				else if(board[i][j]=='k' || board[i][j]=='K')
					King(i,j);
			}
		/*rep(i,1,9)
		{
			rep(j,1,9){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}*/
		int cnt=0;	
		rep(i,1,9)
			rep(j,1,9){
				if(board[i][j]==' ')
					cnt++;
					
				board[i][j]=' ';
			}
					
		cout<<cnt<<endl;
	}
	return 0;
}
