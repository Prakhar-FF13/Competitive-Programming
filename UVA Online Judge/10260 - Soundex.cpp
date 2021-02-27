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

int getCoding(char c) {
    switch(c) {
        case 'B':   return 1;
        case 'F':   return 1;
        case 'P':   return 1;
        case 'V':   return 1;
        case 'C':   return 2;
        case 'G':   return 2;
        case 'J':   return 2;
        case 'K':   return 2;
        case 'Q':   return 2;
        case 'S':   return 2;
        case 'X':   return 2;
        case 'Z':   return 2;
        case 'D':   return 3;
        case 'T':   return 3;
        case 'L':   return 4;
        case 'M':   return 5;
        case 'N':   return 5;
        case 'R':   return 6;
        default:    return -1;
    }
}

int main () {
    RW()
    fsi
    string str;
    while(cin>>str) {
        int prev = -1;
        rep(i, 0, str.length()) {
            int x = getCoding(str[i]);
            if (x == prev)  continue;
            if (x == -1)    {prev = -1;  continue;}
            cout<<x;
            prev = x;
        }
        cout<<endl;
    }
    return 0;
}