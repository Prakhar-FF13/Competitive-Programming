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

typedef class elem {
    public:
        int x;
        int sum;

        elem() { sum = 0; }

        elem(int a, int b) {
            x = a;
            sum = b;
        }
} E;

int main () {
    RW()
    string str;
    while(getline(cin, str)) {
        bool ans = true;
        stringstream ss(str);
        int numb;
        stack<E> st;
        while(ss >> numb) {
            if (numb < 0) {
                if (st.size())  st.top().sum += (-numb);
                st.push(*(new E(numb, 0)));
            } else {
                if (!st.size())     {ans = false; break;}
                else if (-(st.top().x) != numb)     {ans = false; break;}
                else if (st.top().sum >= -(st.top().x))    {ans = false; break;}
                else    st.pop();
            }
        }
        if (ans && st.size() == 0) 
            cout<<":-) Matrioshka!\n";
        else
            cout<<":-( Try again.\n";
    }
    return 0;
}