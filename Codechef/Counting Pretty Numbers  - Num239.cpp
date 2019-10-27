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

int dp[100005][2];

int digitDP(int index, int tight, string numb){
    if(index == numb.length()-1){
        if(tight == 1){
            if(numb[index] < '2')   return 0;
            else if(numb[index] < '3')  return 1;
            else if(numb[index] < '9')  return 2;
        }
        return 3;
    }

    if(dp[index][tight] != -1)
        return dp[index][tight];

    dp[index][tight] = 0;
    int low = 0;
    int high = (tight == 1) ? (numb[index]-'0') : 9;
    rep(i, low, high+1){
        int newTight = (tight & ((i == (numb[index] - '0')) ? 1: 0));
        int partAns = digitDP(index+1, newTight, numb);
        dp[index][tight] += partAns;
    }
    return dp[index][tight];
}

int main(){
    tt(){
        string l,r;
        cin>>l>>r;
        ms(dp, -1, sizeof(dp));
        int o = digitDP(0, 1, r);
        ms(dp, -1, sizeof(dp));
        int p = digitDP(0, 1, l);
        int ans = o - p;
        if(l[l.length()-1] == '2' || l[l.length()-1] == '3' || l[l.length()-1] == '9')
            ans++;
        cout<<ans<<endl;
    }
    return 0;
}
