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
int n,m,a,b,sum;
vi g[100005], OD(100005);
void outDegree(){
	rep(i,1,n+1){
		OD[i] = g[i].size();
	}
}
int ExtractMax(int low, int high){
	if(low == high - 1){
		return (OD[low] >= OD[high] ? low : high);
	}	
	else if(low == high){
		return low;
	}
	else{
		int mid = (high + low)/2;
		int a = ExtractMax(low, mid);
		int b = ExtractMax(mid + 1, high);
		return (OD[a] >= OD[b] ? a : b);
	}
}
void PandD(){
	int curr;
	while(1){
		curr = ExtractMax(1,n);
		if(OD[curr] == 0)
			break;
		sum += 1;
		OD[curr] -= g[curr].size();
		rep(i,0,g[curr].size())
			OD[g[curr][i]] -= 1;
	}
}
int main()
{
	fsi
	cin>>n>>m;
	rep(i,0,m){
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	sum = 0;
	outDegree();
	PandD();
	cout<<sum<<"\n";
	return 0;
}
