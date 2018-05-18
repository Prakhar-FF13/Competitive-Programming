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

int a,b;
class Queen8
{
	private:
		int row[8],linecounter;		//Stores the row number for colums 1 to 8 where the Queen is placed.
	public:
		Queen8(){
			linecounter=0;
			memset(row,0,sizeof(row));
		}
		bool isValid(int r,int c){
			for(int i=0;i<c;i++){
				if(row[i]==r || abs(i-c)==abs(row[i]-r))
					return false;
			}
			return true;
		}
		void backtrack(int c){
			if(c==8 && row[b]==a){
				printf("%2d      %d",++linecounter,row[0]+1);
				for(int i=1;i<8;i++){
					cout<<" "<<row[i]+1;
				}
				cout<<"\n";
			}
			else{
				for(int i=0;i<8;i++){
					if(isValid(i,c)){
						row[c]=i;
						backtrack(c+1);
					}
				}
			}
		}
};

int main()
{
	tt(){
		cin>>a>>b;
		a--,b--;
		Queen8 Q;
		cout<<"SOLN       COLUMN\n";
		cout<<" #      1 2 3 4 5 6 7 8\n\n";
		Q.backtrack(0);
		if(t)
			cout<<"\n";
	}
	return 0;
}

