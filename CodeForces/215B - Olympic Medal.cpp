#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
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
    int n;
    cin>>n;
    int r1Vals[n];  // r1 values.
    rep(i, 0, n)
        cin>>r1Vals[i];
    int m;
    cin>>m;
    int p1Vals[m]; // R1 disk desnity.
    rep(i, 0, m)
        cin>>p1Vals[i];
    int k;
    cin>>k;
    int p2Vals[k]; // r2 Disk desnity.
    rep(i, 0, k)
        cin>>p2Vals[i];
    int A,B;
    cin>>A>>B;
    // to get r2 value, using mout/min = A/B
    // mout/min = p1 * r1 * r1/p2 * r2 * r2
    // r2 = sqrt(p1 * r1 * r1 * B/A*p2)   for a fixed val of r1,p1 and p2.
    double ans = 0;
    double maxR1 = -1;
    rep(i, 0, n)
        maxR1 = max(maxR1, r1Vals[i]*1.0);
    double maxP1 = -1;
    rep(i, 0, m)
        maxP1 = max(maxP1, p1Vals[i]*1.0);
    double minP2 = 1000000007;
    rep(i, 0, k)
        minP2 = min(minP2, p2Vals[i]*1.0);

    ans = maxR1 * sqrt(B * maxP1 / ((B*maxP1) + (A*minP2)));
    printf("%.12lf", ans);
    return 0;
}
