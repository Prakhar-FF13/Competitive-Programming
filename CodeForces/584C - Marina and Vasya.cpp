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
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back
char getDiffCharacter(int index, string s1, string s2){
    char c = 'a';
    while(c == s1[index] || c == s2[index]) c++;
    return c;
}
int main(){
    int t,n;
    cin>>n>>t;
    string s1, s2;
    cin>>s1>>s2;
    char *s3 = new char[n];
    int q = 0;
    int diff1 = 0, diff2 = 0; // diff between s1 and s3, s2 and s3 resp.
    // Copy same q characters into s3
    rep(i, 0, n){
        s3[i] = '.';
        if(s1[i] == s2[i] && n-t-q > 0)
            s3[i] = s1[i], q++;
    }
    // now copy n - t - q characters from s1 to make s3 and s1 have n-t same characters
    int z = n - t - q, ind = 0;
    while(z > 0 && ind < n){
        if(s3[ind] != '.'){ ind++;  continue;}
        s3[ind++] = s1[ind];
        diff2++;
        z--;
    }
    // do the same for s2 and s3 i.e copy n - t - q characters from s2 to s3.
    z = n - t - q;
    ind = 0;
    while(z > 0 && ind < n){
        if(s3[ind] != '.'){ ind++;  continue;}
        s3[ind++] = s2[ind];
        diff1++;
        z--;
    }
    // Remaining characters to be filled have to be not equal to s1[i] and s2[i].
    string ans = "";
    rep(i, 0, n){
        if(s3[i] == '.')
            s3[i] = getDiffCharacter(i, s1, s2), diff2++, diff1++;
        ans += s3[i];
    }
    if(diff1 != t || diff2 != t)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}