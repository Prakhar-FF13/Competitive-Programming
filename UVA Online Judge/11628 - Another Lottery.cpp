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

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
    RW()
    int n,m;
    while(cin>>n>>m){
        if(n == 0)
            break;
        int **arr = new int*[n];
        rep(i, 0, n)
            arr[i] = new int[m];
        ll sum = 0; // total tickets sold in last round. Anyone who wis the last round has the most money. coz of Geometric Progression, Use Sum of GP to check it. sum of n-1 rounds money < money won in nth round.
        rep(i, 0, n)
            rep(j, 0, m){
                cin>>arr[i][j];
                if(j == m-1)
                    sum += arr[i][j];
            }
        rep(i, 0, n){
            if(arr[i][m-1] == 0)
                cout<<"0 / 1"<<endl;
            else{
                ll g = gcd(ll(arr[i][m-1]), sum);
                cout<<arr[i][m-1]/g<<" / "<<sum/g<<endl;
            }
        }
    }
    return 0;
}
