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
string a,b;
int dp[110][110];

int solve(int aInd, int bInd){
    if(aInd == a.length())
        return 0;
    if(bInd == b.length())
        return 0;
    if(dp[aInd][bInd] != -1)
        return dp[aInd][bInd];
    int *x = &dp[aInd][bInd];
    if(a[aInd] == b[bInd])
        *x = solve(aInd+1, bInd+1) + 1;
    else{
        *x = solve(aInd+1, bInd);
        *x = max(*x, solve(aInd, bInd+1));
    }
    return *x;
}

int main(){
    RW()
    int t=1;
    while(getline(cin, a)){
        if(a == "#")
            break;
        getline(cin, b);
        ms(dp, -1, sizeof(dp));
        cout<<"Case #"<<t++<<": you can visit at most "<<solve(0, 0)<<" cities."<<endl;
    }
    return 0;
}
