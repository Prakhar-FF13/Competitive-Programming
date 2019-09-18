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
    set<int> x;
    while(n--){
        int q;
        cin>>q;
        if(x.size() < 4)
            x.insert(q);
    }
    if(x.size() == 1 || x.size() == 2)  cout<<"YES";
    else if(x.size() == 4)              cout<<"NO";
    else{
        int a,b,c;
        auto it = x.begin();
        a = *it; it++;
        b = *it; it++;
        c = *it;
        if(2*a == b+c || 2*b == a+c || 2*c == a+b)
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
