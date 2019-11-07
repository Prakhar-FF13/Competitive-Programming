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

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr(n, vector<int>(m));
    rep(i, 0, n)
        rep(j, 0, m)
            cin>>arr[i][j];
    bitset<1000000> pr;
    pr[0] = 1;
    pr[1] = 1;
    rep(i, 2, 1000000)
        if(pr[i] == 0)
            for(int j = 2*i ; j <= 1000000; j += i)
                pr[j] = 1;
    vi incrementToPrime;
    incrementToPrime.assign(1000000, 0);
    for(int i = 1000000-2 ; i >= 0; i--)
        if(pr[i] == 1)
            incrementToPrime[i] = incrementToPrime[i+1] + 1;

    // checking for rows;
    int ans = MOD;
    rep(i, 0, n){
        int neededTomakePrime = 0;
        rep(j, 0, m)
            neededTomakePrime += incrementToPrime[arr[i][j]];
        ans = min(neededTomakePrime, ans);
    }
    // check for columns;
    rep(i, 0, m){
        int needToMakePrime = 0;
        rep(j, 0, n)
            needToMakePrime += incrementToPrime[arr[j][i]];
        ans = min(needToMakePrime, ans);
    }
    cout<<ans;
    return 0;
}
