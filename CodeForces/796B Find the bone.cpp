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
    int n,m,k;
    cin>>n>>m>>k;
    set<int> holes;
    rep(i, 0, m){
        int x;
        cin>>x;
        holes.insert(x);
    }
    int bonepos = 1;
    if(holes.find(bonepos) != holes.end()){
        cout<<1;
        return 0;
    }
    while(k--){
        int a,b;
        cin>>a>>b;
        if(a == bonepos || b == bonepos){
            bonepos = (a == bonepos) ? b : a;
        }
        if(holes.find(bonepos) != holes.end())
            break;
    }
    cout<<bonepos;
    return 0;
}
