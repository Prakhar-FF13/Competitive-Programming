/*
    Tags - Union Find disjoin sets
    Very good problem involving size of sets.
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
#define repit(a)      for(auto it = a.begin(); it != a.end(); it++)
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

typedef class UnionFind {
    vi p, rank, size;
    public:
        UnionFind(int n) {
            rep(i, 0, n)    p.pb(i), rank.pb(1), size.pb(1);
        }

        int findSet(int i) {
            if (i != p[i])  return p[i] = findSet(p[i]);
            else            return i;
        }

        void unionSet(int i, int j) {
            int x = findSet(i), y = findSet(j);
            if (x == y) return;
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
            } else {
                p[x] = y;
                size[y] += size[x];

                if (rank[x] == rank[y])
                    rank[x]++;
            }
        }

        int getSize(int i) {
            return size[findSet(i)];
        }

} UF;

int main () {
    RW()
    fsi
    int n,m;
    while(cin>>n>>m) {
        if (n == 0) break;
        UF uf(n+1);
        rep(i, 0, m) {
            int k, prev;
            cin>>k;
            if (k) {
                k--;
                cin>>prev;
            }
            while(k--) {
                int x;
                cin>>x;
                uf.unionSet(prev, x);
            }
        }
        cout<<uf.getSize(0)<<endl;
    }
    return 0;
}