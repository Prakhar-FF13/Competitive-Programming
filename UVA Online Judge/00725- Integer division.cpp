#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi				ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 			freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 			1000000007
#define tt() 			int t;cin>>t;while(t--)
#define pb				push_back
#define mp				make_pair
#define ms				memset
#define all(v)			v.begin(),v.end()

int main()
{
	//RW()
	int n;
	int one=0;
	while(1){
		cin>>n;
		int cnt=0;
		if(n==0)
			break;
		else{
			if(one!=0){
				cout<<"\n";
			}
			for(int fghij=1234;fghij<=98765/n;fghij++){
				int temp=fghij;
				int abcde=fghij*n;
				int used=(fghij<10000);
				while(temp){
					used |= 1 << (temp%10);
					temp/=10;
				}
				temp=abcde;
				while(temp){
					used |= 1<<(temp%10);
					temp/=10;
				}
				if(used == (1<<10)-1){
					cnt++;
					printf("%0.5d / %0.5d = %d\n",abcde,fghij,n);
				//	cout<<abcde<<" / "<<fghij<<" = "<<n<<"\n";
				}
			}
			if(cnt==0){
				cout<<"There are no solutions for "<<n<<".\n";
			}
			one++;
			//cout<<"\n";
		}
	}
	return 0;
}
