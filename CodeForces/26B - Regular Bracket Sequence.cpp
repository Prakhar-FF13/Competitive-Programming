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
    int cntO=0,cntC=0;
    stack<char> s;
    int ans=  0;
    rep(i,0,str.length()){
        if(str[i] == '(') s.push('(');
        else{
            if(!s.empty()){
                s.pop();
                ans += 2;
            }
        }
    }
    cout<<ans;
    return 0;
}
