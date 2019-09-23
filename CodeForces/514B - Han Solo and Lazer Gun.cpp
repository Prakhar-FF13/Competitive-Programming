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
    int n,x0,y0;
    cin>>n>>x0>>y0;
    set<double> slopes;
    rep(i, 0, n){
        int x1,y1;
        cin>>x1>>y1;
        double dy = y1-y0;
        double dx = x1-x0;
        double slp;
        if(dx == 0)
            slp = 2000000.0;
        else
            slp = dy/dx;
        slopes.insert(slp);
    }
    cout<<slopes.size();
    return 0;
}
