#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back


int n,m,s;
char g[105][105];
pii getPos(int r,int c, char &lookpos, char nxtmov){
	if(nxtmov == 'F'){
		if(lookpos == 'N')
			return mp(-1,0);
		else if(lookpos == 'S')
			return mp(1,0);
		else if(lookpos == 'O')
			return mp(0,-1);
		else
			return mp(0,1);
	}
	else{
		if(lookpos == 'N'){
			if(nxtmov == 'E')
				lookpos = 'O';
			else
				lookpos = 'L';
		}
		else if(lookpos == 'O'){
			if(nxtmov == 'E')
				lookpos = 'S';
			else
				lookpos = 'N';
		}
		else if(lookpos == 'S'){
			if(nxtmov == 'E')
				lookpos = 'L';
			else
				lookpos = 'O';
		}
		else{
			if(nxtmov == 'E')
				lookpos = 'N';
			else
				lookpos = 'S';
		}
		return mp(0,0);
	}
}
pii nxt;
int SCR(int r,int c, char lookpos, string moves,int index){
	int ans = 0;
	while(index != s){
		//cout<<" r = "<<r<<"  c = "<<c<<"\n";
		nxt = getPos(r, c, lookpos, moves[index++]);
		int t1 = r+nxt.first;
		int t2 = c+nxt.second;
		//cout<<" t1 = "<<t1<<"  t2 = "<<t2<<"\n";
		if(t1 < n && t1 >= 0 && t2 >= 0 && t2 < m){
			if(g[t1][t2] != '#'){
				r = t1;
				c = t2;
				if(g[r][c] == '*'){
					ans++;
					g[r][c] = '.';
				}
			}
		//cout<<"\n--------------------------\n";
		}
	}
	return ans;
}

int main(){
	//RW()
	string str;
	char cur;
	int r,c;
	while(cin>>n>>m>>s){
		if(n == 0)
			break;
		rep(i,0,n)
			rep(j,0,m){
				cin>>g[i][j];
				if(g[i][j] == 'N' || g[i][j] == 'S' || g[i][j] == 'L' || g[i][j] == 'O'){
					r = i;
					c = j;
					cur = g[i][j];
				}
			}
		
		cin>>str;

		cout<<SCR(r, c, cur, str, 0)<<"\n";
	}
	
	return 0;
}
