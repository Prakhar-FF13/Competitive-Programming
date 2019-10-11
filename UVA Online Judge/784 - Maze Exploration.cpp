#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
string str[31];
int n,m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void floodfill(int i, int j){
    str[i][j] = '#';
    rep(l, 0, 4){
        int new_i = i + dx[l];
        int new_j = j + dy[l];
        if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m)
            if(str[new_i][new_j] == ' ')
                floodfill(new_i, new_j);
    }
}

int main(){
    RW()
    int t;
    scanf("%d\n", &t);
    while(t--){
        n = 0;
        while(getline(cin, str[n])){
            n++;
            if(str[n-1][0] == '_')
                break;
        }
        int l,k;
        m = str[0].length();
        rep(i, 0, n)
            rep(j, 0, m)
                if(str[i][j] == '*')
                    l = i, k = j;
        floodfill(l, k);
        rep(i, 0, n){
            cout<<str[i]<<endl;
            str[i].clear();
        }
        str[n].clear();
    }
    return 0;
}
