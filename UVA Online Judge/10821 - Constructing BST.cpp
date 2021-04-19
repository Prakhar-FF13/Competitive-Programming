/*
    Tags - Greedy - Very Good Problem.
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
#define repit(a)      for(auto it = a.begin(); it != a.end(); it++)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;for(int xt = 1; xt <= t; xt++)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

int n, h;

string buildTree(int low, int high, int h) {
    if (low > high) return "";

    int numb = high - low + 1;

    if (numb > (1<<h) - 1)  return "";
    
    int onRight = (1<<(h-1)) - 1;

    int chosenRoot = max(low, high - onRight);

    string ans = to_string(chosenRoot);
    string left = buildTree(low, chosenRoot - 1, h-1);
    if (left != "") ans += " " + left;
    
    string right = buildTree(chosenRoot + 1, high, h-1);
    if (right != "")    ans += " " + right;

    return ans;
}

int main () {
    RW()
    fsi
    int xt = 1;
    while(cin>>n>>h, n) {
        cout<<"Case "<<xt++<<": ";
        string ans = buildTree(1, n, h);
        if (ans == "")  cout<<"Impossible."<<endl;
        else            cout<<ans<<endl;
    }
    return 0;
}