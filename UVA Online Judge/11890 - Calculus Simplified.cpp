/*
    Tags - Very Nice Greedy + Implementation.
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
#define tt() 	        int t;cin>>t;for(int xt = 1; xt <= t; xt++)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

vector<int> arr;
string expr;
int n, i, j;

int solve(int low, int high, int overAllMaxMin) {
    if (low > high) return 0;
    int x = low, y = high;
    int ans = 0, maxMin = overAllMaxMin;
    while(x <= y) {
        if (expr[x] == 'x') {
            int q = maxMin == 1 ? arr[j--] : -1 * arr[i++];
            ans += q;
        }
        else if (expr[x] == '+')    maxMin = overAllMaxMin == 1 ? 1 : 0;
        else if (expr[x] == '-')    maxMin = overAllMaxMin == 0 ? 1 : 0;
        else {
            int q = x;
            int cnt = 0;
            // find matching closing bracket.
            while(true) {
                if (expr[q] == ')') cnt--;
                if (expr[q] == '(') cnt++;
                if (cnt == 0)   break;
                q++;
            }
            int subans = solve(x+1, q-1, maxMin);
            ans += subans;
            x = q;
        }
        x++;
    }
    return ans;
}

int main () {
    RW()
    fsi

    tt() {
        cin>>expr;
        cin>>n;
        arr.assign(n, 0);
        rep(i, 0, n)    cin>>arr[i];
        sort(all(arr));
        i = 0, j = n-1;
        // expression start ind, expression end in, whatToDo -> 1 means maximize, 0 means minimize.
        cout<<solve(0, expr.size()-1, 1)<<endl;
    }

    return 0;
}