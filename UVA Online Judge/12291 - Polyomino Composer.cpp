/*
    Tags - Implementation
    good problem
*/

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
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

string bp[20], sp[20];
int n,m;

bool matchP(int i, int j, int rs, int cs) {
    for(int k = i - rs; k < i - rs + m; k++) {
        for(int l = j - cs; l < j - cs + m; l++) {
            int spE = sp[k - i + rs][l - j + cs];
            if (k < 0 || l < 0 || k >= n || l >= n) {
                if (spE == '*') return false;
                else    continue;
            }
            int bpE = bp[k][l];
            if (spE == '.')  continue;
            if (spE == '*' && bpE == '*')   bp[k][l] = 'x';
            else return false;
        }
    }
    return true;
}

int main(){
    RW()
    while(cin>>n>>m) {
        if (n == 0) break;
        rep(i,0,n)  cin>>bp[i];
        rep(i,0,m)  cin>>sp[i];
        int columnStart = 0, rowStart = 0;
        rep(i, 0, m) {
            int j;
            for(j = 0; j < m; j++) {
                if (sp[i][j] == '*') {
                    rowStart = i, columnStart = j;
                    break;
                }
            }
            if (j != m) break;
        }

        bool ans = true;
        rep(i, 0, n)
            rep(j, 0, n)
                if (bp[i][j] == '*')
                    ans = ans & matchP(i, j, rowStart, columnStart);

        if (ans)    cout<<1;
        else        cout<<0;

        cout<<endl;
    }
    return 0;
}
