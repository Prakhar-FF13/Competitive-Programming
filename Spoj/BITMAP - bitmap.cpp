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
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
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

int mat[200][200];
int n,m;
queue<pii> q;

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0 , 0, -1, 1};

void printMat(){
    rep(i, 0 ,n){
        rep(j , 0, m)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void bfs(){

    while(!q.empty()){
        pii top = q.front();
        int dist = mat[top.first][top.second];
        q.pop();
        //printMat();
        rep(i, 0, 4){
            int newX = top.first + dx[i];
            int newY = top.second + dy[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m)
                if(dist + 1 < mat[newX][newY]){
                    mat[newX][newY] = dist + 1;
                    q.push(mp(newX, newY));
                }
        }
    }

}

int main(){
    tt(){
        cin>>n>>m;
        rep(i, 0, n)
            rep(j, 0, m)
                mat[i][j] = 400000;
        while(!q.empty())
            q.pop();
        rep(i, 0 ,n){
            string str;
            cin>>str;
            rep(j , 0, m){
                int x = str[j] - '0';
                if(x == 1){
                    mat[i][j] = 0; q.push(mp(i,j));
                }
            }
        }
        bfs();
        printMat();
    }
    return 0;
}
