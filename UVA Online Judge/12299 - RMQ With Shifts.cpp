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

typedef class SegmentTree {
    public:
        vi st, A;
        int n;
        SegmentTree(int n, vi &x) {
            st.assign(4*n+5, 0);
            A = x;
            this->n = n;
            build(0, n-1);
        }

        int l(int p) {return p<<1;}
        int r(int p) {return (p<<1) + 1;}

        void build(int L, int R, int p=1) {
            if (L == R) {
                st[p] = A[L];
            } else {
                int m = (L+R)/2;
                build(L,m,l(p));
                build(m+1,R,r(p));
                st[p] = min(st[l(p)], st[r(p)]);
            }
        }

        int query(int i, int j, int L, int R, int p = 1) {
            if (i > j)  return 1e9; // invalid query.
            if (R < i)  return 1e9; // wrong range.
            if (L > j)  return 1e9; // wrong range.
            if (L >= i && R <= j)   return st[p]; // in range.
            int m = (L+R)/2;
            int left = query(i, j, L, m, l(p));
            int right = query(i, j, m+1, R, r(p));
            return min(left, right);
        }

        int query(int i, int j) {
            return query(i, j, 0, n-1);
        }

        void update(int i, int j, int L, int R, int elem ,int p=1) {
            if (L > R || i > j || L > j || R < i)   return;
            if (L == R) {
                A[L] = elem;
                st[p] = elem;
            } else {
                int m = (L+R)/2;
                update(i, j, L, m, elem, l(p));
                update(i, j, m+1, R, elem, r(p));
                st[p] = min(st[l(p)], st[r(p)]);
            }
        }

        void update(int i, int j, int elem) {
            update(i, j, 0, n-1, elem);
        }

        void showArrayAfterUpdate() {
            for(int i = 0 ;i  <n ; i++)
                cout<<A[i]<<" ";
            cout<<endl;
        }
} ST;

int main () {
    RW()
    fsi
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    rep(i, 0, n)    cin>>arr[i];
    ST sgt(n, arr);
    while(q--) {
        string str;
        cin>>str;
        char type[100], nums[10000];
        sscanf(str.c_str(), "%[^(]s", type);

        if (string(type) == "query") {
            sscanf(str.c_str(), "query(%[^)]s", nums);
        } else {
            sscanf(str.c_str(), "shift(%[^)]s", nums);
        }
        
        vector<int> inds;
        string x = string(nums);
        for(int i = 0; i < x.size(); ) {
            string temp = "";
            while(x[i] != ',')
                temp += x[i++];
            i++;
            inds.pb(stoi(temp) - 1);
        }

        if (string(type) == "query") {
            cout<<sgt.query(inds[0], inds[1])<<endl;
        } else {
            int f = sgt.A[inds[0]];
            for(int i = 0; i < inds.size() - 1 ; i++)
                sgt.update(inds[i], inds[i], arr[inds[i+1]]);

            sgt.update(inds[inds.size()-1], inds[inds.size()-1], f);
        }

        // sgt.showArrayAfterUpdate();
    }
    return 0;
}