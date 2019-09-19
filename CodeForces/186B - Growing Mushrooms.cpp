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
int n,t1,t2,k;

int cmp(pair<double, int> a, pair<double, int> b){
    double grA = a.first;
    double grB = b.first;
    if(grA != grB){
        return grA < grB;
    }else{
        int posA = a.second;
        int posB = b.second;
        return posA > posB;
    }
}
int main(){
    cin>>n>>t1>>t2>>k;
    double percentage = k*1.0/100.0;
    vector<pair<double, int> > growers(n);
    rep(i, 0, n){
        int a,b;
        cin>>a>>b;
        double growthAFirst = a*t1 - a*t1*percentage + b*t2;
        double growthBFirst = b*t1 - b*t1*percentage + a*t2;
        double maxGrowth = max(growthAFirst, growthBFirst);
        growers[i] = mp(maxGrowth, i+1);
    }
    sort(growers.begin(), growers.end(), cmp);
    for(int i = n-1; i >= 0 ; i--){
        pair<double, int> x = growers[i];
        printf("%d %.2lf\n", x.second, x.first);
    }
    return 0;
}
