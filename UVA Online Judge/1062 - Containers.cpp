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

int getInt(char c) {
    return c - 'A';
}

int main () {
    RW()
    string str;
    int x = 1;
    while(cin>>str) {
        if (str == "end")   break;
        vector<stack<char> > arr;
        int last[26];
        int n = str.length();

        rep(i, 0, n)    last[getInt(str[i])] = i;

        rep(i, 0, n) {
            int val = getInt(str[i]), ind = -1, mindiff = 1e9+7;

            for(int j = 0; j < arr.size(); j++) {
                int valTop = getInt(arr[j].top());
                int diff = valTop - val;
                
                if (diff < 0)   continue; // stack top is smaller - stack top has B, str[i] has D
                else if (diff == 0) {   // stack top = str[i].
                    ind = j;
                    break;
                }
                else if (diff < mindiff){  
                // stack top > str[i] - stack top has Z, str[i] is say A.
                    mindiff = diff;
                    ind = j;
                }
            }

            if (ind == -1) {
                stack<char> s;
                s.push(str[i]);
                arr.pb(s);
            } else {
                arr[ind].push(str[i]);
            }
        }
        cout<<"Case "<<x++<<": "<<arr.size()<<endl;
    }
    return 0;
}