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
class FenWick2DTree{
	private:
		int n;
		vi ft[100];
	public:
		FenWick2DTree(int size){
			n = size;
			rep(i,0,100)
				ft[i].assign(n+5, 0);
		}
		void Build_Update(int x, int y, int val){
			for( ; x <= n ; x += x & -x)
				for(int y1 = y ; y1 <= n ; y1 += y1 & -y1)
					ft[x][y1] += val;
		}
		int Query(int x, int y){
			int sum = 0;
			for( ; x > 0 ; x -= x & -x)
				for(int y1 = y ; y1 > 0 ; y1 -= y1 & -y1)
					sum += ft[x][y1];
			return sum;
		}
		int Query(int x1,int y1, int x2, int y2){
			int a = Query(x2,y2);
			int b = Query(x1-1,y1-1);
			int c = Query(x2,y1-1);
			int d = Query(x1-1, y2);
			return (a - d - c + b);
		}
		void DisplayTree(){
			cout<<"\n-----------------------------\nBuilt Tree is -> \n";
			rep(i,1,n+1){
				rep(j,1,n+1)
					cout<<ft[i][j]<<" ";
				cout<<"\n";
			}
			cout<<"\n-----------------------------\n";
		}
};
int main()
{
	int n;
	cout<<"Enter size of 2d Matrix(square) : ";
	cin>>n;
	int arr[n+2][n+2];
	cout<<"Enter elements of 2d matrix : \n";
	rep(i,1,n+1)
		rep(j,1,n+1)
			cin>>arr[i][j];
	FenWick2DTree F(n);
	rep(i,1,n+1)
		rep(j,1,n+1)
			F.Build_Update(i,j,arr[i][j]);
	F.DisplayTree();
	int q;
	cout<<"Enter number of queries : ";
	cin>>q;
	while(q--){
		int a,b,c,d;
		cout<<"Enter rectangle coordinate (1 based indexing) : ";
		cin>>a>>b>>c>>d;
		cout<<"Query("<<a<<","<<b<<","<<c<<","<<d<<") : ";
		cout<<F.Query(a,b,c,d)<<"\n";
	}
	return 0;
}
