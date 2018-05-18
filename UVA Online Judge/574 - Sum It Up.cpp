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
int c,k;
void SumItUp(vi num, int t, int n, int currsum, vi curr, int index, vi used[]){
	if(currsum == t){
		rep(i,0,150){
			if(used[i] == curr)
				return;
		}
		used[k++] = curr;
		rep(i,0,curr.size()){
			cout<<curr[i];
			if(i!=curr.size()-1)
				cout<<"+";
		}
		cout<<"\n";
		c++;
	}
	else if(index < n){
		curr.pb(num[index]);
		SumItUp(num, t, n, currsum+num[index], curr, index+1, used);
		curr.pop_back();
		SumItUp(num, t, n, currsum, curr, index+1, used);
	}
}
int main()
{

	int t,n;
	while(cin>>t>>n){
		if(n == 0)
			break;
		vi num(n);
		rep(i,0,n)
			cin>>num[i];
		vi curr;
		vi used[150];
		c = 0,k = 0;
		cout<<"Sums of "<<t<<":\n";
		SumItUp(num, t, n, 0, curr, 0, used);
		if(c == 0)
			cout<<"NONE\n";
	}
	return 0;
}
