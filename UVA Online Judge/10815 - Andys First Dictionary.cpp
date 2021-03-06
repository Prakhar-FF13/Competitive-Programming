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

int main () {
    RW()
    fsi
    string str;
    set<string> s;
    while(getline(cin, str)) {
        string cur = "";
        rep(i, 0, str.length()) {
            if (str[i] >= 'a' && str[i] <= 'z')
                cur += str[i];
            else if (str[i] >= 'A' && str[i] <= 'Z')
                cur += str[i];
            else {
                transform(all(cur), cur.begin(), ::tolower);
                if (cur.length())   s.insert(cur);
                cur = "";
            }
        }
        transform(all(cur), cur.begin(), ::tolower);
        if (cur.length())   s.insert(cur);
    }
    for(auto it = s.begin(); it != s.end(); it++)
        cout<<*(it)<<endl;
    return 0;
}