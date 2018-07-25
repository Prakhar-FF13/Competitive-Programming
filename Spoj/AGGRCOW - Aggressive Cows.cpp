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

bool isPossible(int n, int c, int pos[], int d){
	
	c--;
	int curcow = pos[0];
	rep(i, 1, n){
		if(pos[i] - curcow >= d){
			curcow = pos[i];
			c--;
		}
	}
	return (c > 0) ? false:true;
}

int calculate(int n, int c, int pos[], int low, int high){
	if(low<=high){
		int mid = ( high + low )/ 2;
		if(isPossible(n, c, pos, mid)){
			return max(mid, calculate(n, c, pos, mid+1, high));	
		}
		else{
			return calculate(n, c, pos, low, mid-1);	
		}
	}
	return -1;
}

int main(){
	fsi
	tt(){
		int n,c;
		cin>>n>>c;
		int *pos = new int[n];
		rep(i,0,n)
			cin>>pos[i];
		sort(pos, pos + n);
		cout<<calculate(n, c, pos, 0, pos[n-1])<<"\n";
		cout<<"\n";
	}
	return 0;
}
