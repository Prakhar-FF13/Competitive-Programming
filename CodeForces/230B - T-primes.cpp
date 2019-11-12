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
bitset<1000005> pr;
int main(){
    int n;
    cin>>n;
    pr[0] = 1;
    pr[1] = 1;
    for(int i = 2; i < 1000005; i++)
        if(pr[i] == 0){
            for(int j = 2*i ; j < 1000005 ; j+= i)
                pr[j] = 1;
        }
    rep(i, 0, n){
        ll x;
        cin>>x;
        ll sqrtX = sqrt(x);
        if((sqrtX * sqrtX == x) && pr[sqrtX] == 0)
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
