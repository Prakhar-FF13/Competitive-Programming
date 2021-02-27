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

bool cmp(pair<char, int> a, pair<char, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main () {
    RW()
    fsi
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin,str);
        transform(all(str), str.begin(), ::tolower);
        
        int n = str.length();
        unordered_map<char, int> m;
        
        rep(i, 0, n)    if (isalpha(str[i]))    m[str[i]]++;
        
        vector<pair<char, int> > arr;
        for(auto it = m.begin(); it != m.end(); it++)   arr.pb(*(it));
        
        sort(all(arr), cmp);
        
        string ans = "";
        int x = arr.size()-1;
        int cnt = arr[x].second;
        
        while(x >= 0 && arr[x].second == cnt)   ans += arr[x--].first;
        
        reverse(all(ans));
        cout<<ans<<endl;
    }
    return 0;
}