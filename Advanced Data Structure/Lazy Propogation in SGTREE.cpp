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
#define RW() 	freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()

class LazyTree
{
	private:
		vi A,st,lazy;
		int n;
		int left(int p){ return (p<<1);
		}
		int right(int p){ return ((p<<1)+1);
		}
		void build(int p,int L,int R){
			if(L==R){
				st[p]=A[L];
			}
			else{
				int mid=(L+R)/2;
				build(left(p),L,mid);
				build(right(p),mid+1,R);
				st[p]=st[left(p)]+st[right(p)];
			}
		}
		void UpdateRange(int p,int L,int R,int i,int j,int val){
			if(lazy[p]!=0){
				st[p]+=(R-L+1)*lazy[p];
				if(L!=R){
					lazy[left(p)]+=lazy[p];
					lazy[right(p)]+=lazy[p];
				}
				lazy[p]=0;
			}
			if(j<L || i>R || L>R)
				return;
			if(i<=L && j>=R){
				st[p]+=(R-L+1)*val;
				if(L!=R){
					lazy[left(p)]+=val;
					lazy[right(p)]+=val;
				}
			}
			else{
				int mid=(L+R)/2;
				UpdateRange(left(p),L,mid,i,j,val);
				UpdateRange(right(p),mid+1,R,i,j,val);
				st[p]=st[left(p)]+st[right(p)];
			}
		}
		int RSQ(int p,int L,int R,int i,int j){
			if(j<L || i>R || L>R)
				return 0;
			if(lazy[p]!=0){
				st[p]+=(R-L+1)*lazy[p];
				if(L!=R){
					lazy[left(p)]+=lazy[p];
					lazy[right(p)]+=lazy[p];
				}
				lazy[p]=0;	
			}
			if(i<=L && j>=R){
				return st[p];
			}
			else{
				int mid=(L+R)/2;
				int p1=RSQ(left(p),L,mid,i,j);
				int p2=RSQ(right(p),mid+1,R,i,j);
				return (p1+p2);
			}
		}
	public:
		LazyTree(vi &_A){
			A=_A;
			n=(int)A.size();
			st.assign(4*n,0);
			lazy.assign(4*n,0);
			build(1,0,n-1);
		}
		void Update(int i,int j,int val){
			UpdateRange(1,0,n-1,i,j,val);
		}
		int RSQ(int i,int j){
			return RSQ(1,0,n-1,i,j);
		}
		void Display(){
			cout<<"\nSegment Tree Values : ";
			rep(i,0,3*n){
				cout<<st[i]<<" ";
			}
			cout<<"\nArray values : ";
			rep(i,0,n){
				cout<<A[i]<<" ";
			}
		}
};
int main()
{
	int arr[]={1,2,3,4,5,6};
	vi _A(arr,arr+6);
	LazyTree T(_A);
	T.Display();
	cout<<"\n------------------------------------------------------------------------------------------------------";
	cout<<"\n\nNormal Sum Queries before Operations ---> \n";
	cout<<"\nRSQ(1,4) : "<<T.RSQ(1,4);
	cout<<"\nRSQ(0,3) : "<<T.RSQ(0,3);
	cout<<"\nRSQ(0,5) : "<<T.RSQ(0,5);
	cout<<"\nRSQ(2,2) : "<<T.RSQ(2,2);
	T.Update(2,2,3);
	T.Update(1,4,2);
	T.Update(0,3,7);
	T.Update(0,5,-2);
	cout<<"\n------------------------------------------------------------------------------------------------------";
	T.Display();
	cout<<"\n------------------------------------------------------------------------------------------------------";
	cout<<"\n\nSum Queries after Operations ---> \n";
	cout<<"\nRSQ(1,4) : "<<T.RSQ(1,4);
	cout<<"\nRSQ(0,3) : "<<T.RSQ(0,3);
	cout<<"\nRSQ(0,5) : "<<T.RSQ(0,5);
	cout<<"\nRSQ(2,2) : "<<T.RSQ(2,2);
	cout<<"\n------------------------------------------------------------------------------------------------------";
	return 0;	
}
