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
    char str[3001];
    while(gets(str)) {
        stack<string> st;
        int cnt = 0, n = strlen(str);
        int i;
        for(i = 0 ; i< n ; i++) {
            //cout<<i<<" "<<cnt<<" "<<str[i]<<" "<<(st.size() ?  st.top() : " ")<<endl;
            if (str[i] == '{' || str[i] == '[' || str[i] == '<') {
                st.push(string(1, str[i]));
                cnt++;
            } else if (str[i] == '(') {
                if (i+1 < n && str[i+1] == '*') {
                    i++;
                    st.push("(*");
                } else {
                    st.push("(");
                }
                cnt++;
            } else if (str[i] == '}') {
                cnt++;
                if (st.size() && st.top() == "{")   { st.pop(); continue;}
                break;
            } else if (str[i] == ']') {
                cnt++;
                if (st.size() && st.top() == "[")   { st.pop(); continue;}
                break;
            } else if (str[i] == '>') {
                cnt++;
                if (st.size() && st.top() == "<")   { st.pop(); continue;}
                break;
            } else if (str[i] == ')') {
                cnt++;
                if (st.size() && st.top() == "(")   { st.pop(); continue;}
                break;
            } else if (str[i] == '*' ) {
                cnt++;
                if (i+1 && str[i+1] == ')') {
                    i++;
                    if (st.size() && st.top() == "(*")  { st.pop(); continue;}
                    break;
                }
            } else
                cnt++;
         }
         if (i < n)             cout<<"NO "<<cnt<<endl;
         else if (st.size())    cout<<"NO "<<cnt+1<<endl;
         else                   cout<<"YES"<<endl;
    }
}