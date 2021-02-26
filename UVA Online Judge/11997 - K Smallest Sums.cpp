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

int main () {
    RW()
    fsi
    int n;
    while(cin>>n) {
        vector<int> kSums(n);   // contains n least sums

        rep(l, 0, n) {
            priority_queue<int, vector<int>, greater<int> > pq;

            rep(i, 0, n) {
                if (l == 0) // only one array then n leastsums are array elements itself.
                    cin>>kSums[i];
                else {
                    // generate cummulative least n sums.
                    // kSums + elements of new array. take minimum sums.
                    int x;
                    cin>>x;
                    rep(j, 0, n)
                        pq.push(kSums[j] + x);  // push all n^2 pairs.
                }
            }
            if (l == 0) continue;
            
            int x = 0;    // take n smallest sums.
            while(x < n) {
                kSums[x] = pq.top();
                pq.pop();
                x++;
            }
        }
        cout<<kSums[0];
        rep(i,1,n)
            cout<<" "<<kSums[i];
        cout<<endl;
    }
    return 0;
}