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

vi ans, // stores k stamps. (stores best combination of stamps)
   tmp, // when backtracking stores a combination of k stamps. 
   upperB; // upperbound of stamps. 

int maxSeq;

// returns max sequence reachable using stamp combination stored in tmp.
int check(int h, int len) {
    // check whether including this stamp we form a sequence 1,2,3,4....
    // and check max such sequence length.
    vi checkSequence;
    // at max 200 length sequence can be made since h is small.
    // 200 is an arbitrary number chosen since h and k are both small.
    checkSequence.assign(200, -1);

    // we can use dp to check max sequence reached.
    // checkSequence[i] will store stamps remaining to be used.
    // example checkSequence[4] = 3 -> means 4 is reachable
    // and we can still use 3 more stamps, -1 means not reachable.

    checkSequence[0] = h; // h stamps can be used.

    rep(i, 0, len+1) {    // all stamps so far.
        int smp = tmp[i];

        int j = 1;
        while(j < 200) {
            if (j - smp >= 0) {
                checkSequence[j] = max(
                    checkSequence[j - smp] - 1, // can we reach this number using stamp i.
                    checkSequence[j]
                );
            }
            j++;
        }
    }

    // for(int i = 0; i <= len; i++)
    //     cout<<tmp[i]<<" ";
    // cout<<endl;

    // for(int i =0 ; i < 10; i++)
    //     cout<<checkSequence[i]<<" ";
    // cout<<endl;

    // check what is max sequence formed.
    int j = 1;
    while(checkSequence[j] != -1) j++;

    return j-1;
}


void getStamps(int h, int k, int ind) {
    if (ind == k)   return; // one combination of k stamps generated.

    // tmp[ind-1] is previous stamp. next stamp will be greater than this stamp.
    // example if stamp 3 is included then
    // next stamp to check for inclusion is 4, 5, ....
    int lower = ind-1 >= 0 ? tmp[ind-1] + 1 : 1;

    // we will not check all the stamps example if with stamp 1, 3 and k = 3
    // we can get a sequence of upto 7, so we only check upto stamp 8.
    // there is no point in adding a stamp of 9 if we can never reach 8 using 1, 3.
    // if we include 1,3,9 with k = 3 then we can never make a sequence upto 8.
    // so including 9 is usless.
    int upper = ind-1 >= 0 ? upperB[ind-1] + 1 : h;

    // now backtrack and check for all combination, add one stamp then recurse.

    for(int i = lower; i <= upper; i++) {
        // include ith stamp.
        tmp[ind] = i;

        // check seuqence.
        int mxSeq = check(h, ind);

        if (mxSeq > maxSeq) {
            maxSeq = mxSeq;
            ans = tmp;
        }

        upperB[ind] = mxSeq;

        getStamps(h, k, ind+1);
    }
}

void solve(int h, int k) {
    ans.clear();
    tmp.clear();
    tmp.assign(k, 0); // space for k stamps.
    upperB.assign(k, 0);
    maxSeq = 0;


    getStamps(h, k, 0); // call with index 0;

    for(int i = 0; i < ans.size(); i++){
        printf("%3d", ans[i]);
    }
    printf(" ->%3d\n", maxSeq);
}

int main () {
    RW()
    fsi
    int h,k;
    while(cin>>h>>k) {
        if (h == 0) break;
        solve(h, k);
    }
    return 0;
}