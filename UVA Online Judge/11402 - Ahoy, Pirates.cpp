/*
    Tags - Very good problem involving Segment Tree
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

string str;

typedef class SegTree {
    vi st, lazy;
    int n;
    public:
        int l(int x)    {return x<<1;}
        int r(int x)    {return (x<<1) + 1;}

        SegTree(int n) {
            st.assign(4*n+5, 0);
            lazy.assign(4*n+5, -1);
            this->n = n;
            build(0, n-1);
        }

        void build(int L, int R, int node=1) {
            if (L == R)
                st[node] = str[L] - '0';
            else {
                int m = (L+R)/2;
                build(L, m, l(node));
                build(m+1, R, r(node));
                st[node] = st[l(node)] + st[r(node)];
            }
        }

        void propogate(int L, int R, int node) {
            if (lazy[node] != -1) {
                if (lazy[node] == 0)
                    st[node] = 0;
                else if (lazy[node] == 1)
                    st[node] = R-L+1;
                else if (lazy[node] == 2)
                    st[node] = R-L+1 - st[node];

                if (L != R) {
                    if (lazy[node] == 0 || lazy[node] == 1)
                        lazy[l(node)] = lazy[r(node)] = lazy[node];
                    else {
                        lazy[l(node)] = 1 - lazy[l(node)];
                        lazy[r(node)] = 1 - lazy[r(node)];
                    }
                }
                else {
                    if (lazy[node] == 0)
                        str[L] = '0';
                    else if (lazy[node] == 1)
                        str[L] = '1';
                    else    str[L] = str[L] == '1' ? '0' : '1';
                }
                
                lazy[node] = -1;
            }
        }

        int RSQ(int L, int R, int i, int j, int node=1) {
            propogate(L, R, node);
            if (i > j || L > j || R < i)  return 0;
            if (L >= i && R <= j)   return st[node];
            else {
                int m = (L+R)/2;
                return RSQ(L, m, i, min(m, j), l(node)) +
                    RSQ(m+1, R, max(i, m+1), j, r(node));
            }
        }

        int RSQ(int i, int j) {
            return RSQ(0, n-1, i, j);
        }

        void update(int L, int R, int i, int j, int elem, int node=1) {
            propogate(L, R, node);
            if (i > j || L > j || R < i)  return;
            if (L >= i && R <= j) {
                lazy[node] = elem;
                propogate(L, R, node);
            } else {
                int m = (L+R)/2;
                update(L, m, i, min(j, m), elem, l(node));
                update(m+1, R, max(i, m+1), j, elem, r(node));
                propogate(L, m, l(node));
                propogate(m+1, R, r(node));
                st[node] = st[l(node)] + st[r(node)];
            }
        }

        void update(int i, int j, int elem) {
            update(0, n-1, i, j, elem);
        }

        void displaySGT(int n) {
            cout<<str<<endl;
            for(int i = 0; i <= n ; i++)
                printf("%3d ", i);
            cout<<endl;
            for(int i = 0; i <= n ; i++)
                printf("%3d ", st[i]);
            cout<<endl;
        }
} ST;

int main () {
    RW()
    fsi
    int t;
    cin>>t;
    for(int cp = 1 ; cp <= t; cp++) {
        str = "";
        int m;
        cin>>m;
        rep(j, 0, m) {
            int x;  cin>>x;
            string q;   cin>>q;
            while(x--)  str += q;
        }
        ST sgt(str.size());
        int q;
        cin>>q;
        cout<<"Case "<<cp<<":"<<endl;
        int xc = 1;
        while(q--) {
            char c;
            cin>>c;
            int a,b;
            cin>>a>>b;
            //cout<<c<<" "<<a<<" "<<b<<endl;
            //sgt.displaySGT(4*str.size());
            if (c == 'F')
                sgt.update(a, b, 1);
            else if (c == 'E')
                sgt.update(a, b, 0);
            else if (c == 'I')
                sgt.update(a, b, 2);
            else
                cout<<"Q"<<xc++<<": "<<sgt.RSQ(a, b)<<endl;
        }
    }
    return 0;
}