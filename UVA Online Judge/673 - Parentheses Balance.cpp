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
    int x;
    cin>>x;
    getc(stdin);
    while(x--) {
        char str[140];
        gets(str);
        int n = strlen(str);
        if (n == 0) {
            cout<<"Yes"<<endl;
            continue;
        }
        stack<char> st;
        int i;
        for(i = 0; i < n; i++) {
            if (str[i] == '(' || str[i] == '[') st.push(str[i]);
            else if (st.size() == 0) break;
            else if (str[i] == ')' && st.top() != '(')    break;
            else if (str[i] == ']' && st.top() != '[')      break;
            else    st.pop();
        }
        if (i < n || st.size())
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}