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
vector<int> g[66];
map<string, int> posToNum;
int visited[68];
int parent[68];
int minPos[68];
bool found;
void bfs(int src, int dest){
    queue<int> q;
    q.push(src);
    int dist = 0;
    minPos[src] = dist;
    while(!q.empty() && found == false){
        int top = q.front();
        q.pop();
        if(visited[top] == 1)   continue;
        visited[top] = 1;
        for(int i = 0; i < g[top].size() ; i++){
            int nei = g[top][i];
            if(visited[nei] != 1){
                parent[nei] = top;
                minPos[nei] = minPos[parent[nei]] + 1;
                q.push(nei);
                if(nei == dest) found=true;
            }
        }
    }
}

int main(){
    /*Generate Mapping of form a1->1, a2->2, .... h8->64*/
    int numb=1;
    for(int i = 0; i < 8 ; i++){
        string curr = ""; curr += char('a' + i);
        for(char j = '1' ; j <= '8' ; j++){
            string temp = curr + j;
            posToNum[temp] = numb++;
        }
    }
    /* Generate Graph */
    int board[9][9];
    numb = 1;
    rep(i, 1, 9)
        rep(j , 1, 9)
            board[i][j] = numb++;

    rep(i, 1, 9)
        rep(j, 1, 9){
            if(i-1 >= 1 && j-2 >= 1) g[board[i][j]].pb(board[i-1][j-2]);
            if(i-1 >= 1 && j+2 <= 8) g[board[i][j]].pb(board[i-1][j+2]);
            if(i+1 <= 8 && j-2 >= 1) g[board[i][j]].pb(board[i+1][j-2]);
            if(i+1 <= 8 && j+2 <= 8) g[board[i][j]].pb(board[i+1][j+2]);
            if(i-2 >= 1 && j-1 >= 1) g[board[i][j]].pb(board[i-2][j-1]);
            if(i-2 >= 1 && j+1 <= 8) g[board[i][j]].pb(board[i-2][j+1]);
            if(i+2 <= 8 && j-1 >= 1) g[board[i][j]].pb(board[i+2][j-1]);
            if(i+2 <= 8 && j+1 <= 8) g[board[i][j]].pb(board[i+2][j+1]);
        }

    string xx,yy;
    /* Answer Queries */
    while(cin>>xx>>yy){
        ms(minPos, 0, sizeof(minPos));
        ms(visited, -1, sizeof(visited));
        ms(parent, -1, sizeof(parent));
        /* Run BFS from this xx */
        found = false;
        bfs(posToNum[xx], posToNum[yy]);
        cout<<"To get from "<<xx<<" to "<<yy<<" takes "<<minPos[posToNum[yy]]<<" knight moves."<<endl;
    }
    return 0;
}
