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
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main(){
    int n,m,cnt=0;
    cin>>n>>m;
    string str[n];
    rep(i, 0, n)
        cin>>str[i];

    // check if rows are sorted;
    rep(i, 0, n-1){
        if(str[i] > str[i+1]){ // if row i is not smaller than row i+1
            // check which column violates it.
            int j;
            for(j = 0 ; j < m ; j++){
                if(str[i][j] > str[i+1][j])
                    break;
            }
            rep(k, 0, n)
                str[k][j] = 'a'; // fill the jth row with smallest character or remove the jth row both are fine.

            cnt++; // increment removed column counter.
            i = -1;  // i=-1 to recheck if there are any other columns other than current j which violate the smaller condition.
        }
    }
    cout<<cnt;
    return 0;
}
