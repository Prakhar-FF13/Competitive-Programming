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

unordered_map<string, int> m;

// precalculate all values.
void getNumber() {
    queue<string> q;

    for(char c = 'a'; c <= 'z' ; c++)   q.push(string(1, c));

    int c = 1;
    while(!q.empty()) {
        string x = q.front();
        q.pop();
        m[x] = c++;

        if (x.length() == 5)    // max-length is reached no need to create new words.
            continue;

        for(char last = x[x.length()-1]+1; last <= 'z' ; last++)  // create new words by appending a character to current string.
            q.push(x + last);
    }
}

int main () {
    RW()
    fsi
    string w;
    getNumber();
    while(cin>>w) {
        if (m.find(w) == m.end())   cout<<0<<endl;
        else                        cout<<m[w]<<endl;
    }
    return 0;
}