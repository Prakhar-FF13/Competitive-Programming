#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
    string str;
    cin>>str;
    string ans = "";
    int first2;
    int i = 0;
    while(str[i] != '2' && i < str.length()){
        ans += str[i];
        i++;
    }
    int j = i+1;
    int onesAfterfirst2 = 0;
    while(j < str.length()){
        if(str[j] == '1')   onesAfterfirst2++;
        j++;
    }
    sort(ans.begin(), ans.end());
    rep(i, 0, onesAfterfirst2)
        ans += '1';
    rep(k, i, str.length()){
        if(str[k] != '1')
            ans += str[k];
    }
    cout<<ans;
    return 0;
}
