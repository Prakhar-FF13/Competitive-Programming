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
    string str;
    cin>>str;
    int n = str.length();
    if(str.length() <= 3)   cout<<0;
    else if(str.length() == 4 && str != "bear") cout<<0;
    else{
        vi bears;
        rep(i, 0, n-3){
            if(str[i] == 'b' && str[i+1] == 'e' && str[i+2] == 'a' && str[i+3] == 'r')
                bears.pb(i);
        }
        if(bears.size() == 0)   cout<<0;
        else{
            ll ans = 0;
            n--;
            rep(x, 0, bears.size()){
                int b_pos = bears[x];
                int i     = x>0 ? b_pos - bears[x-1] : b_pos + 1;
                int r_pos = b_pos + 4 - 1;
                int j     = n - r_pos + 1;
                //cout<<b_pos<<" "<<i<<" "<<r_pos<<" "<<j<<endl;;
                ans += i*j;
            }
            cout<<ans;
        }
    }
    return 0;
}
