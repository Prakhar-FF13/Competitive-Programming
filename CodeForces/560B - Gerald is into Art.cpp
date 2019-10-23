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

int main(){
    int x, y, a, b, c, d; scanf("%d %d\n%d %d\n%d %d\n", &x, &y, &a, &b, &c, &d);

    bool possible(0);

    if(a + c <= x && b <= y && d <= y){possible = 1;}
    if(a + d <= x && b <= y && c <= y){possible = 1;}
    if(b + c <= x && a <= y && d <= y){possible = 1;}
    if(b + d <= x && a <= y && c <= y){possible = 1;}

    if(a + c <= y && b <= x && d <= x){possible = 1;}
    if(a + d <= y && b <= x && c <= x){possible = 1;}
    if(b + c <= y && a <= x && d <= x){possible = 1;}
    if(b + d <= y && a <= x && c <= x){possible = 1;}

    puts(possible ? "YES" : "NO");
    return 0;
}
