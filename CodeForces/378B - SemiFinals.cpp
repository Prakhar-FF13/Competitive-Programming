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
    ll n;
    cin>>n;
    vector<ll> a, b, A(n), B(n);
    a.assign(n, 0);
    b.assign(n, 0);
    int aC = 0, bC = 0;
    int k = n/2;
    rep(i, 0, n){
        cin>>A[i]>>B[i];
        if(i < k){
            a[i] = 1;
            b[i] = 1;
        }
    }
    while(aC + bC != n){
        if(A[aC] <= B[bC]){
            a[aC] = 1; aC++;
        }
        else{
            b[bC] = 1; bC++;
        }
    }
    rep(i, 0, a.size())
        cout<<a[i];
    cout<<endl;
    rep(i, 0, b.size())
        cout<<b[i];
    return 0;
}
