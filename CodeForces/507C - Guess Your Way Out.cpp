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

// solution in goodNotes

int main(){
    ll height, node;
    cin>>height>>node;
    char cmd = 'L';
    ll h = height, n = node, ans = 0;
    while(true){
        ll halfNodes = pow(2, h-1);
        bool requiredNodeDir = (n <= halfNodes);
        if(cmd == 'L'){
            if(requiredNodeDir){
                ans += 1;
                cmd = 'R';
            }
            else{
                n -= halfNodes;
                ans += (halfNodes<<1);
            }
            h--;
        }else{
            if(!requiredNodeDir){
                ans += 1;
                n -= halfNodes;
                cmd = 'L';
            }
            else
                ans += (halfNodes<<1);
            h--;
        }
        if(h == 0){
            cout<<ans;
            break;
        }
    }
    return 0;
}
