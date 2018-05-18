#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class SegmentTree
{
	private:
		vi st,A;
		int n;
		int left(int p){ return p<<1; }
		int right(int p){ return (p<<1)+1; }
		
		void build(int p,int L,int R){
			if(L==R)
				st[p]=L;
			else
			{
				build(left(p),L,(L+R)/2);
				build(right(p),(L+R)/2+1,R);
				int p1=st[left(p)],p2=st[right(p)];
				st[p]=(A[p1]<=A[p2]) ? p1 : p2;
			}
		}
		//Range Minimum Query !!!
		int RMQ(int p,int L,int R,int i,int j){
			if(i>R || j<L) return -1;
			if(L>=i && R<=j) return st[p];
			int p1=RMQ(left(p),L,(L+R)/2,i,j);
			int p2=RMQ(right(p),(L+R)/2+1,R,i,j);
			if(p1==-1) return p2;
			if(p2==-1) return p1;
			return (A[p1]<=A[p2]) ? p1 : p2;
		}
		int Update(int p,int L,int R,int idx,int val){
			if(idx<L || idx>R) return st[p];
			if(idx==L && idx==R) {
				A[L]=val;
				st[p]=L;
			}
			else
			{
				int mid=(L+R)/2,p1,p2;
				p1=Update(left(p),L,mid,idx,val);
				p2=Update(right(p),mid+1,R,idx,val);
				st[p]=(A[p1]<=A[p2]) ? p1 : p2;
			}
		}
	public:
		SegmentTree(const vi &_A){
			A=_A;n=(int)A.size();
			st.assign(4*n,0);
			build(1,0,n-1);
		}
		int RMQ(int i ,int j){
			return RMQ(1,0,n-1,i,j);
		}
		void Update(int i,int j){
			Update(1,0,n-1,i,j);
		}
		void Display(){
			for(int i=0;i<n;i++)
				cout<<A[i]<<" ";
			cout<<endl;
		}
};
int main()
{
	int arr[]={1,10,2,9,3,6,7,4,11,5,8};
	vi A(arr,arr+11);
	SegmentTree st(A);
	cout<<"\nInitial Array elements : ";
	st.Display();
	cout<<"RMQ(1,3) = "<<st.RMQ(1,3)<<"\n";
	cout<<"RMQ(2,6) = "<<st.RMQ(2,6)<<"\n";
	cout<<"RMQ(1,9) = "<<st.RMQ(1,9)<<"\n";
	cout<<"RMQ(5,7) = "<<st.RMQ(5,7)<<"\n";
	cout<<"RMQ(4,8) = "<<st.RMQ(4,8)<<"\n";
	cout<<"RMQ(3,11) = "<<st.RMQ(3,11)<<"\n";
	cout<<"\nAfter updating Array elements : \n";
	st.Update(2,73);
	st.Update(5,15);
	st.Update(7,34);
	st.Update(10,21);
	st.Update(3,8);
	st.Display();
	cout<<"RMQ(1,3) = "<<st.RMQ(1,3)<<"\n";
	cout<<"RMQ(2,6) = "<<st.RMQ(2,6)<<"\n";
	cout<<"RMQ(1,9) = "<<st.RMQ(1,9)<<"\n";
	cout<<"RMQ(5,7) = "<<st.RMQ(5,7)<<"\n";
	cout<<"RMQ(4,8) = "<<st.RMQ(4,8)<<"\n";
	cout<<"RMQ(3,11) = "<<st.RMQ(3,11)<<"\n";
	
	return 0;
}
