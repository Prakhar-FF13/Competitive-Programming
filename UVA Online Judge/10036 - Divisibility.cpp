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
int n,k;
vi arr;
bool possible;

void solve(int num, int ind){
    if(ind == arr.size()){
        if(num%k == 0)
            possible = true;
        return;
    }
    solve(num + arr[ind], ind+1);
    solve(num - arr[ind], ind+1);
}

int main(){
    tt(){
        cin>>n>>k;
        possible = false;
        arr.clear();
        rep(i, 0, n){
            int x;
            cin>>x;
            arr.pb(x);
        }
        solve(arr[0], 1);
        if(possible)
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;
    }
    return 0;
}
