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
int r,c,sr,sc,dr,dc,x,y,nob;
char ch;
int movex[] = {1,0,-1,0};
int movey[] = {0,1,0,-1};
bool visited[1005][1005];
int dist[1005][1005];
bool valid(pii a, int j){
	int l = a.first + movex[j];
	int m = a.second + movey[j];
	if(l >=0 && l<r && m>=0 && m<c)
		return true;
	else
		return false;
}
int main()
{
	//RW()
	while(cin>>r>>c){
		if(r == 0)
			break;
		int t;
		ms(visited ,false, sizeof(visited));
		ms(dist, -1, sizeof(dist));
		cin>>t;
		while(t--){
			cin>>x>>nob;
			while(nob--){
				cin>>y;
				visited[x][y] = true;
				dist[x][y] = MOD;
			}
		}
		cin>>sr>>sc;
		cin>>dr>>dc;
		queue<pii> q;
		q.push(mp(sr,sc));
		visited[sr][sc] = true;
		dist[sr][sc] = 0;
		while(!q.empty()){
			pii curr = q.front(); q.pop();
			for(int j = 0; j < 4; j++){
				if(valid(curr, j) && !visited[curr.first + movex[j]][curr.second + movey[j]]){
					visited[curr.first + movex[j]][curr.second + movey[j]] = true;
					dist[curr.first + movex[j]][curr.second + movey[j]] = dist[curr.first][curr.second] + 1;
					q.push(mp(curr.first + movex[j], curr.second + movey[j]));
				}
			}
		}
		cout<<dist[dr][dc]<<"\n";
	}
	return 0;
}
