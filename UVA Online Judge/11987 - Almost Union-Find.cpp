/*
    Tags - Extremely good problem - Union find disjoint sets.
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
    vi p, rank, size, sum, mapping;
    int dummy;
    public:
        UnionFind(int n, int m) {
            for(int i = 0 ;i < n ; i++) {
                p.pb(i);
                rank.pb(1);
                sum.pb(i);
                size.pb(1);
                mapping.pb(i);                    
            }
            dummy = n;
            for(int j = 0; j < m ; j++) {
                p.pb(j+n);
                rank.pb(1);
                sum.pb(0);  // dummy.
                size.pb(1);
                mapping.pb(j+n);
            }
        }

        int findSetHelper(int i) {
            if (i != p[i])  return p[i] = findSetHelper(p[i]);
            else            return i;
        }

        int findSet(int i) {
            return findSetHelper(mapping[i]);
        }

        void unionSet(int i, int j) {
            i = mapping[i], j = mapping[j];
            int x = findSet(i), y = findSet(j);
            if (x == y) return;
            if (rank[x] > rank[y]) {
                p[y] = x;
                size[x] += size[y];
                sum[x] += sum[y];
            } else {
                p[x] = y;
                size[y] += size[x];
                sum[y] += sum[x];

                if (rank[x] == rank[y])
                    rank[x]++;
            }
        }

        void changeSet(int i, int q) {
            int x = mapping[i];
            int y = mapping[q];

            int pi = findSet(x);
            int s  = findSet(y);
            if (pi == s)    return;

            // logically ith is now a dummy.
            // we need to assign a value to set s and make i point to this node.

            mapping[i] = dummy; // when next time ith is referenced we check
            p[dummy] = s;
            size[dummy] = 1;
            rank[dummy] = 1;
            sum[dummy] = i;   
            
            // decrease size of original set.
            size[pi] -= 1;
            sum[pi] -= i;

            // increase size of new set s.
            size[s] += 1;
            sum[s] += i;

            dummy++;    // dummy is now used, set next for another move operation.
        }

        int getSize(int i) {
            return size[findSet(i)];
        }

        int getSum(int i) {
            return sum[findSet(i)];
        }

        void displayData() {
            rep(i, 0, p.size())
                cout<<p[i]<<" ";
            cout<<endl;
            rep(i, 0, mapping.size())
                cout<<mapping[i]<<" ";
            cout<<endl;
        }
} UF;

int main () {
    RW()
    fsi
    int n,m;
    while(cin>>n>>m) {
        UF uf(n+1, m);
        rep(i, 0, m) {
            int x, p, q;
            cin>>x;
            if (x == 1) {
                cin>>p>>q;
                uf.unionSet(p, q);
            } else if (x == 2) {
                cin>>p>>q;
                uf.changeSet(p, q);
            } else {
                cin>>p;
                cout<<uf.getSize(p)<<" "<<uf.getSum(p)<<endl;
            }
        }
    }
    return 0;
}