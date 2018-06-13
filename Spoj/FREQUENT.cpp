#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pair< int, pii > > viii;
#define rep(i,a,b)	for(int i=a;i<b;i++)

class FREQUENT
{
	private:
		viii st;
		vi A;
		int n;
		int left(int p){
			return (p<<1);
		}
		int right(int p){
			return (p<<1)+1;
		}
		void build(int p,int L,int R){
			if(L==R){
				st[p].first=1;
				st[p].second.first=st[p].second.second=L;
			}
			else{
				int mid=(L+R)/2;
				build(left(p),L,mid);
				build(right(p),mid+1,R);
				int p1=left(p);
				int p2=right(p);
				if(A[mid]==A[mid+1]){
					int L1=(mid-st[left(p)].second.second+1)*(A[mid]==A[st[left(p)].second.second]);
					int R1=(mid+1-st[right(p)].second.first+1)*(A[mid+1]==A[st[right(p)].second.first]);
					int S1=(st[right(p)].second.first-st[left(p)].second.second+1)*(A[st[right(p)].second.first]==A[st[left(p)].second.second]);
					st[p].first=max(L1,max(R1,S1));
					st[p].second.first=st[left(p)].second.first;
					st[p].second.second=st[right(p)].second.second;
				}
				st[p].first=max(st[p].first,max(st[left(p)].first,st[right(p)].first));
				st[p].second.first=st[left(p)].second.first;
				st[p].second.second=st[right(p)].second.second;
			}
		}
		int RFQ(int p,int L,int R,int i,int j){
			if(i<L || j>R || L>R)
				return -1;
			if(L>=i && R<=j){
				return st[p].first;
			}
			
		}
	public:
};
int main(){
	return 0;
}
