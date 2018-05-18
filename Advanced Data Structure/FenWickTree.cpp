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
class FenWickTree{
	private:
		vi ft;
		int n;
	public:
		FenWickTree(int size){
			ft.assign(size + 5, 0);
			n = size;
		}
		void build_update(int x, int val){
			for(; x <= n+1 ; x += x & -x)
				ft[x] += val;
		}
		int query(int x){
			int sum = 0;
			for(; x > 0 ; x -= x & -x)
				sum += ft[x];
			return sum;
		}
		int query(int x,int y){
			return (query(y) - query(x - 1));
		}
};
int main()
{
	int n;
	cout<<"Enter size of the array : ";
	cin>>n;
	int arr[n+1];	// 1 Based Indexing .
	cout<<"Enter array elements : ";
	rep(i,1,n+1)
		cin>>arr[i];
	FenWickTree F(n);
	for(int i = 1; i<=n ; i++)
		F.build_update(i, arr[i]);
	int q;
	cout<<"\nEnter number of queries : ";
	cin>>q;
	while(q--){
		int a,b;
		cout<<"Enter range : ";
		cin>>a>>b;
		cout<<F.query(a,b)<<"\n";
	}
}
