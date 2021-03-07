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
    int t,doc = 1;
    scanf("%d", &t);
    while(t--) {
        string str;
        vector<string> x;
        
        while(getline(cin, str)) {
            if (str == "END")   break;
            
            int len = str.length();
            string cur = "";
            
            rep(i, 0, len) {
                if (str[i] >= 'a' && str[i] <= 'z')    cur += str[i];
                else {
                    if (cur.length())   x.pb(cur);
                    cur = "";
                }
            }
            if (cur != "")  x.pb(cur);
        }
        
        int len = x.size();
        int ansI = 0, ansJ = len-1;
        unordered_map<string, int> m;
        
        rep(i, 0, len)  m[x[i]] = i; // just to count unique words.

        int i = 0, j = 0, unique = m.size();
        m.clear();

        while(j < len) {
            m[x[j]]++;
            while (m.size() == unique) {
                if (j - i + 1 < ansJ - ansI + 1)    ansJ = j, ansI = i;

                if (m[x[i]] == 1)   m.erase(x[i]);
                else                m[x[i]]--;

                i++;
            }
            j++;
        }

        cout<<"Document "<<doc++<<": "<<ansI+1<<" "<<ansJ+1<<endl;
    }
    return 0;
}