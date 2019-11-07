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
    int n;
    cin>>n;
    vector<ll> arr(n+2), suffixI, prefixI;
    suffixI.assign(n+2, 0);
    prefixI.assign(n+2, 0);
    rep(i, 1, n+1){
        cin>>arr[i];
        prefixI[i] = prefixI[i-1] + arr[i];
    }
    arr[0] = 0;
    arr[n+1] = 0;
    string binNumber;
    cin>>binNumber;
    ll sum1 = 0;
    rep(i, 0, binNumber.length())
        if(binNumber[i] == '1')
            sum1 += arr[i+1];
    for(int i = binNumber.length()-1; i >= 0; i--){
        suffixI[i+1] += suffixI[i+2];
        if(binNumber[i] == '1')
            suffixI[i+1] += arr[i+1];
    }
    ll sum2 = 0;
    /*rep(i, 0, n+2)
        cout<<suffixI[i]<<" ";
    cout<<endl;
    rep(i, 0, n+2)
        cout<<prefixI[i]<<" ";
    cout<<endl;*/
    rep(i, 0, binNumber.length()){
        if(binNumber[i] == '1'){
            int ind = i+1;
            ll s = prefixI[ind-1] + suffixI[ind+1];
            sum2 = max(s, sum2);
        }
    }
    cout<<max(sum1, sum2);
    return 0;
}
