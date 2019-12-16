#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int n, row[101], x, y, dx, dy;
int dist[101][int(1e5+1)];
int vis[101][int(1e5+1)];

bool validToMove(int x, int *y){
	if(x >= 1 && x <= n){
		if(*y < 1)	return false;
		if(row[x] < *y) *y = row[x];
		return true;
	}
	return false;
}

int dirX[] = {-1, 1, 0, 0};
int dirY[] = {0, 0, -1, 1};
void bfs(int x, int y, int dx, int dy){
	int ans;
	dist[x][y] = 0;
	vis[x][y] = 1;
	queue<pii> q;
	q.push({x, y});
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		rep(i, 0, 4){
			int nx = top.first + dirX[i];
			int ny = top.second + dirY[i];
			if(validToMove(nx, &ny) && vis[nx][ny] == -1){
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[top.first][top.second] + 1;
				if(nx == dx && ny == dy){
					cout<<dist[nx][ny];
					return;
				}
				q.push({nx, ny});
			}
		}
	}
}

int main(){
	RW()
	cin>>n;
	rep(i, 1, n+1){
		cin>>row[i];
		row[i]++;
	}
	cin>>x>>y>>dx>>dy;
	if(x == dx && y == dy){
		cout<<0;
		return 0;
	}
	ms(vis, -1, sizeof(vis));
	bfs(x, y, dx, dy);
	/*for(auto it = dist.begin() ; it != dist.end() ; it++){
		cout<<it->first.first<<", "<<it->first.second<<"  :  "<<it->second<<endl;
	}*/
    return 0;
}