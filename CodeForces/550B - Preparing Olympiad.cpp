#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<functional>
#include<numeric>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
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
int n,l,r,x,ans;
int arr[20];
void possibilities(int index, int n, vector<int> cis){
    if(index >= n){
        int len = cis.size();
        /*rep(i,0,len)    cout<<cis[i]<<" ";
        cout<<endl;*/
        sort(cis.begin(), cis.end());
        int sum = accumulate(cis.begin(), cis.end(), 0);
        if(sum < l || sum > r)   return;
        int ez = cis[0];
        int hard = cis[len-1];
        if(hard-ez < x) return;
        ans++;
        return;
    }else{
        possibilities(index+1, n, cis);
        cis.pb(arr[index]);
        possibilities(index+1, n, cis);
        cis.pob();
    }
}
int main(){
    cin>>n>>l>>r>>x;
    ans = 0;
    rep(i,0,n)
        cin>>arr[i];
    vector<int> cis;
    possibilities(0, n, cis);
    cout<<ans;
    return 0;
}
