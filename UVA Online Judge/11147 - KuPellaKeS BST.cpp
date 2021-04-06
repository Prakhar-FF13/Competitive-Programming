/*
    Tags - Very Good DNC problem - must solve
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

// index is root.
pll getDiff(int index, int low, int high, vector<ll> &sum) {
    ll left = 0, right = 0;

    // left sum.
    if (index - 1 >= low)   left += sum[index - 1] - (low - 1 >= 0 ? sum[low-1] : 0);

    // right sum.
    if (index + 1 <= high)  right += sum[high] - sum[index];

    return mp(left, right);
}

string generateKuPellaKesBST(int low, int high, vector<ll> &arr, vector<ll> &sum) {
    string ans = "";

    if (low == high) { // only one node - make root and return;
        ans += to_string(arr[low]);
        return ans;
    }

    // choose the root such that the sum is minimum.
    ll ansRoot, ansDiff = MOD, ansLeftS = -1e9;

    rep(i, low, high + 1) {
        // duplicates can only occur on LHS side of BST.
        if (i + 1 <= high && arr[i+1] == arr[i])    continue;

        // make i the root.
        pll x = getDiff(i, low, high, sum);
        ll diff = abs(x.first - x.second);
        
        // this sum is smaller than current or sum is equal but left tree sum is greater.
        if (diff < ansDiff || (diff == ansDiff && x.first > ansLeftS)) {
            ansLeftS = x.first; // new left sum tree.
            ansDiff = diff;     // new smallest diff.
            ansRoot = i;        // store ith as root.
        }
    }

    ans += to_string(arr[ansRoot]);

    if (ansRoot != low && ansRoot != high)
        ans += "(" + generateKuPellaKesBST(low, ansRoot-1, arr, sum) + ","
            + generateKuPellaKesBST(ansRoot + 1, high, arr, sum) + ")";
    
    else if (ansRoot != high)
        ans += "(" + generateKuPellaKesBST(ansRoot + 1, high, arr, sum) + ")";
    
    else if (ansRoot != low)
        ans += "(" + generateKuPellaKesBST(low, ansRoot-1, arr, sum) + ")";

    return ans;
}

int main () {
    RW()
    fsi
    tt() {
        int n;
        cin>>n;
        vector<ll> x(n), sumx(n);
        rep(i, 0, n)    cin>>x[i];
        // sort so that if we make ith as root then all smaller will lie on left.
        sort(all(x));
        // prefix sum, to get left sum and right sum in O(1)
        sumx[0] = x[0];
        rep(i, 1, n)    sumx[i] += x[i] + sumx[i-1];

        // recursively generate the string.
        string ans = generateKuPellaKesBST(0, n-1, x, sumx);
        cout<<"Case #"<<xt<<": "<<ans<<endl;
    }
    return 0;
}