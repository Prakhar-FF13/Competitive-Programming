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

int getQuadrant(pii a, pii b){
    int p = a.first - b.first;
    int q = a.second - b.second;
    int d = p*q;
    return d;
}

int main(){
    int n;
    while(cin>>n){
        if(n == 0)
            break;
        vii pts;
        rep(i, 0, n){
            int x,y;
            cin>>x>>y;
            pts.pb(mp(x,y));
        }
        pii midpt = pts[int((n-1)/2)];
        int stans_score = 0, ollie_score = 0;
        rep(i, 0, n){
            int x = getQuadrant(midpt, pts[i]);
            if(x > 0)
                stans_score++;
            if(x < 0)
                ollie_score++;
        }

        cout<<stans_score<<" "<<ollie_score<<endl;

    }
    return 0;
}
