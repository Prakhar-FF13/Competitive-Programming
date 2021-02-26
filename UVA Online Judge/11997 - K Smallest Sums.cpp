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
            // if only one array then k least sums are array elements itself.
            if (l== 0) {rep(i, 0, n)    cin>>kSums[i]; sort(all(kSums)); continue;}
            
            // now we try to generate all n^2 pairs and queue to keep only k smallest.
            priority_queue<int> pq;
            vector<int> temp(n); // stores 2nd, 3rd...nth etc array elements.

            rep(i, 0, n)    {cin>>temp[i];  pq.push(temp[i] + kSums[0]);}
            sort(all(temp));

            rep(i, 0, n)
                rep(j, 1, n)
                    if (pq.top() > temp[i] + kSums[j]) { // out of all n^2 pairs keep only k smallest.
                        pq.pop();   // remove bigger sum
                        pq.push(temp[i] + kSums[j]); // add smaller sum.
                    } else // since array is sorted if previous element sum is greater than next element sum will for sure be greater, so ignore.
                        break;
            
            int x = n-1;
            while(pq.size()) {
                kSums[x--] = pq.top();
                pq.pop();
            }
        }
        cout<<kSums[0];
        rep(i,1,n)
            cout<<" "<<kSums[i];
        cout<<endl;
    }
    return 0;
}