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

bool MonkeyandoiledBamboo(int arr[], int curr, int n){
	int d=0;
	rep(i,0,n){
		if(arr[i]-d > curr)
			return false;
		else if(arr[i]-d == curr)
			curr--;
		d = arr[i];	
	}	
	
	if(curr >= 0)
		return true;
	else
		return false;
}
int main()
{
	int low,mid,high;
	int n,ans;
	int c=0;
	tt(){
		cin>>n;
		int arr[n];
		rep(i,0,n){
			cin>>arr[i];
		}
		low = 1;
		high = (int)(1e7);
		while(low<=high){
			mid = (low+high)/2;
			if(MonkeyandoiledBamboo(arr, mid, n)){
				ans = mid;
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		cout<<"Case "<<++c<<": "<<ans<<"\n";
	}
	return 0;
}
