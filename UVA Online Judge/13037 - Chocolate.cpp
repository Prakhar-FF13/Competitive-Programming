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

void printAns(set<int> a, set<int> b, set<int> c) {
    int ans1 = 0, ans2 = 0;
    for(auto it = a.begin(); it != a.end(); it++) {
        int x = *it;
        if (b.find(x) == b.end() && c.find(x) == c.end())   ans1++;
    }
    for(auto it = b.begin(); it != b.end(); it++) {
        int x = *it;
        if (c.find(x) != c.end() && a.find(x) == a.end())   ans2++;
    }
    cout<<ans1<<" "<<ans2<<endl;
}

int main () {
    RW()
    fsi
    int t;
    cin>>t;
    rep(cas, 1, t+1) {
        int l,r,s;
        cin>>l>>r>>s;
        
        set<int> a,b,c;
        rep(i, 0, l)    {int x; cin>>x; a.insert(x);}
        rep(i, 0, r)    {int x; cin>>x; b.insert(x);}
        rep(i, 0, s)    {int x; cin>>x; c.insert(x);}

        cout<<"Case #"<<cas<<":"<<endl;
        printAns(a, b, c);
        printAns(b, a, c);
        printAns(c, a, b);
    }
    return 0;
}