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
    tt(){
        ll n, k;
        cin>>n>>k;
        ll arr[n];
        rep(i, 0, n)
            cin>>arr[i];

        ll ans = 0;
        rep(i, 0, n){
            rep(j , i+1, n)
                if(arr[i] > arr[j])
                    ans++;
        }
        ans = ans * k; // inversion in array repeated k times.
        rep(i, 0, n){
            ll inv = 0;
            rep(j , 0, n)
                if(arr[i] > arr[j])
                    inv++;
            ans += ((k*(k-1))/2)*inv; // elemets smaller than arr[i] are all inversion when we concatenate our array.
        }
        cout<<ans<<endl;
    }
    return 0;
}
