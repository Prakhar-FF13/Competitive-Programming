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
        int n,k,p,ans;
        cin>>n>>k>>p;
        int arr[110];
        rep(i, 0, n)
            cin>>arr[i];
        if(p == 0){
            if(k & 1){
                ans = -1;
                rep(i, 0, n)
                    ans = max(ans, arr[i]);
            }else{
                ans = max(arr[1], arr[n-2]);
                rep(i, 1, n-1)
                    ans = max(ans, min(arr[i-1], arr[i+1]));
            }
        }else{
            if(k & 1){
                ans = 1e9+7;
                rep(i, 0, n)
                    ans = min(ans, arr[i]);
            }else{
                ans = min(arr[1], arr[n-2]);
                rep(i, 1, n-1)
                    ans = min(ans, max(arr[i-1], arr[i+1]));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
