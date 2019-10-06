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

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}


int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double x1 = a*1.0/b*1.0;
    double x2 = c*1.0/d*1.0;
    if(x1 == x2)    cout<<0<<"/"<<1;
    else if(x1 < x2){
        int GCD = gcd(b*c - a*d, b*c);
        cout<<(b*c-a*d)/GCD<<"/"<<(b*c)/GCD;
    }else{
        int GCD = gcd(a*d - b*c, a*d);
        cout<<(a*d-b*c)/GCD<<"/"<<(a*d)/GCD;
    }
}
