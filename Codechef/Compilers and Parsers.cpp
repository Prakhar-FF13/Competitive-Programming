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
	tt(){
		string expr;
		cin>>expr;
		int valid = 0, ans = 0;
		rep(i,0,expr.length()){
			if(expr[i] == '<'){
				valid++;
			}
			else{
				valid--;
			}
			if(valid == 0)
				ans = i + 1;
			if(valid < 0)
				break;
		}
		
		cout<<ans<<"\n";
	}
}
