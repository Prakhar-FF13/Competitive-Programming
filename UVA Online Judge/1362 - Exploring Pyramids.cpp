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
string str;
ll dp[310][310];
ll solve(int l, int r){
    if(l == r)
        return 1LL;
    if(dp[l][r] != -1)
        return dp[l][r];
    if(str[l] != str[r])
        return 0LL;
    dp[l][r] = 0;
    for(int k = l+2 ; k <= r; k++)
        if(str[l] == str[k])
            dp[l][r] = (dp[l][r] + solve(l+1, k-1) * solve(k, r))%(ll(1e9));

    return dp[l][r];
}

int main(){
    RW()
    while(cin>>str){
        ms(dp, -1, sizeof(dp));
        cout<<solve(0, str.length()-1)<<endl;
    }
    return 0;
}
