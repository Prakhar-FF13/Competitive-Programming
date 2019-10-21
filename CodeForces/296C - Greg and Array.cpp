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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> arr;
    arr.assign(n+2, 0);
    vector<ll> increaseByD; // to increase element arr[i] by this much.
    rep(i,1,n+1)
        cin>>arr[i];
    increaseByD.assign(n+2, 0);

    // increase element from l to r by d.
    vector<pair<ll, pll>> operations(m+2);
    rep(i, 1, m+1){
        int l,r,d;
        cin>>l>>r>>d;
        operations[i] = mp(d, mp(l,r));
    }

    vector<ll> operationsDone;
    operationsDone.assign(m+2, 0);

    // perform operations from x to y.
    rep(i, 0, k){
        int x,y;
        cin>>x>>y;
        operationsDone[x]++;
        operationsDone[y+1]--;
    }

    // get total number of times an operation is done.
    rep(i, 1, m+2)
        operationsDone[i] += operationsDone[i-1];

    // for each operations calculate increment of that part.
    rep(i, 1, m+1){
        pair<ll, pll> oper = operations[i];
        ll d = oper.first;
        ll l = oper.second.first;
        ll r = oper.second.second;
        increaseByD[l] += d*operationsDone[i];
        increaseByD[r+1] -= d*operationsDone[i];
    }

    // sum of the d to get total increment.
    rep(i, 1, n+2)
        increaseByD[i] += increaseByD[i-1];

    // display the array;
    rep(i, 1, n+1)
        cout<<arr[i]+increaseByD[i]<<" ";
    return 0;
}
