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
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int arr[1010][1010];
int row[1010], col[1010];

int main(){
    RW()
    fsi
    int n,m,k;
    cin>>n>>m>>k;
    rep(i, 0, n){
        rep(j, 0, m){
            cin>>arr[i][j];
        }
    }
    rep(i, 0, n)
        row[i] = i;
    rep(j, 0, m)
        col[j] = j;
    while(k--){
        char c;
        int x,y;
        cin>>c>>x>>y;
        switch (c)
        {
        case 'c': swap(col[x-1], col[y-1]);
                  break;
        case 'r': swap(row[x-1], row[y-1]);
                  break;
        case 'g': cout<<arr[row[x-1]][col[y-1]]<<endl;
                  break;
        default:
            break;
        }
    }
    return 0;
}
