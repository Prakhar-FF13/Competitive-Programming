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
ll **mat;
ll f[2][1];

void multiplyMat(ll **mat1, ll **mat2){
    ll tl = (mat1[0][0]%MOD*mat2[0][0]%MOD + mat1[0][1]%MOD*mat2[1][0]%MOD)%MOD;
    ll tr = (mat1[0][0]%MOD*mat2[0][1]%MOD + mat1[0][1]%MOD*mat2[1][1]%MOD)%MOD;
    ll bl = (mat1[1][0]%MOD*mat2[0][0]%MOD + mat1[1][1]%MOD*mat2[1][0]%MOD)%MOD;
    ll br = (mat1[1][0]%MOD*mat2[0][1]%MOD + mat1[1][1]%MOD*mat2[1][1]%MOD)%MOD;
    mat1[0][0] = tl;
    mat1[0][1] = tr;
    mat1[1][0] = bl;
    mat1[1][1] = br;
}

void power(ll p, ll **mat){
    ll **res = new ll*[2];
    rep(i, 0, 2)
        res[i] = new ll[2];
    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 0;
    while(p){
        if(p & 1)
            multiplyMat(res, mat);
        multiplyMat(mat, mat);
        p = p>>1;
    }
    mat[0][0] = res[0][0];
    mat[0][1] = res[0][1];
    mat[1][0] = res[1][0];
    mat[1][1] = res[1][1];
}

int main(){
    ll x,y,n;
    cin>>x>>y>>n;
    f[0][0] = y;
    f[1][0] = x;
    ll ans;
    mat = new ll*[2];
    rep(i, 0, 2)
        mat[i] = new ll[2];
    mat[0][0] = 1;
    mat[0][1] = -1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    if(n==1)
        ans = x;
    else if(n==2)
        ans = y;
    else{
        power(n-2, mat);
        ans = (mat[0][0]%MOD * f[0][0]%MOD + mat[0][1]%MOD * f[1][0]%MOD)%MOD;
    }
    if(ans < 0)
        ans += MOD;
    cout<<ans;
    return 0;
}
