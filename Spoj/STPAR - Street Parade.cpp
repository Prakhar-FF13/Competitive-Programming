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
	stack<int> sidestreet;
	vi newstreet;
	while(cin>>n){
		if(n == 0)
			break;
		int arr[n];
		newstreet.clear();
		while(!sidestreet.empty())
			sidestreet.pop();
		rep(i,0,n)
			cin>>arr[i];
		int curr = 1;
		rep(i,0,n){
			int k = curr;
			if(arr[i] == curr){
				newstreet.pb(arr[i]);
				curr++;
			}
			if(!sidestreet.empty()){
				while(!sidestreet.empty()){
					int q = sidestreet.top();
					if(q == curr){
						newstreet.pb(q);
						sidestreet.pop();
						curr++;
					}
					else
						break;
				}
				if(arr[i] == curr){
					newstreet.pb(arr[i]);
					curr++;
				}
			}
			if(k == curr){
				sidestreet.push(arr[i]);
			}
		}
		if(sidestreet.empty())
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}
