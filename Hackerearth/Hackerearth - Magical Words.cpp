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

int main()
{
	RW()
	string str;
	tt(){
		ll ans = 0;
		cin>>str;
		int n = str.length();
		if(n == 1)
			cout<<1<<"\n";
		else if(n == 2)
			cout<<(str[0] == str[1] ? 4 : 2);
		else{
			int table[n+5][n+5];
			rep(i,0,n){
				table[i][i] = 1;
				ans += 1;
				if(i!=n-1){
					if(str[i] == str[i+1]){
						table[i][i+1] = 1;
						ans += 4;
					}
					else
						table[i][i+1] = 0;
				}
			}
			for(int l = 3 ; l < n+1 ; l++){
				rep(i,0,n){
					int j = i + l -1;
					if(str[i] == str[j] && table[i+1][j-1] == 1){
						table[i][j] = 1;
						ans += l*l;
					}
					else{
						table[i][j] = 0;
					}
				}
			}
			rep(i,0,n){
				rep(j,0,n)
					if(i<=j)
						cout<<table[i][j];
					
				cout<<"\n";
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
