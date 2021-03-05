/*
    Tags - Stack
    good problem
*/

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
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

int priority(char c) {
    switch(c) {
        case ')':   return 0;
        case '/':   return 2;
        case '*':   return 2;
        case '+':   return 1;
        case '-':   return 1;
        default:    return -1;
    }
}

string infixToPostfix(string str) {
    str = '(' + str + ')';
    int n = str.length();
    string ans = "";
    stack<char> st;
    for(int i = 0 ; i < n ; i++) {
        int pr = priority(str[i]);

        if (str[i] == '(')  st.push(str[i]); // opening bracket.
        else if (pr == -1)  ans += str[i]; // is a number.
        else if (pr == 0) {         // is a closing bracket.
            while(st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {  // is an operator.
            while(st.size() && priority(st.top()) >= pr) {
                ans += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    return ans;
}

int main () {
    RW()
    int t;
    scanf("%d\n\n", &t);
    while(t--) {
        char c;
        string str = "";
        while(1) {
            c = getc(stdin);
            if (c == '\n' || c == EOF)  break;
            str += c;
            getc(stdin);
        }
        cout<<infixToPostfix(str)<<endl;
        if (t)
            cout<<endl;
    }
    return 0;
}