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

int BSearch(int key, int index, int low, int high, vi states[])
{
	int mid;
	while(low <= high)
	{
		if(low == high)
		{
			if(key <= states[index][high])
				return states[index][low];
			else 
				return -1;
		}
		else
		{
			mid = (low+high)/2;
			if(key == states[index][mid] )
				return states[index][mid];
			else if(key > states[index][mid]){
				if(low == mid)
					low = low + 1;
				else
					low = mid;
			}
			else
				if(high == mid + 1)
					high = high -1;
				else
					high = mid;
		}
	}
}
int main()
{

	string str;
	cin>>str;
	vi states[100];
	rep(i,0,str.length())
		states[((int)str[i]) - 65].pb(i);
		
	int Q;
	cin>>Q;
	string asked;
	while(Q--)
	{
		int k = 1;
		int last,first;
		int curr = 0;
		cin>>asked;
		rep(i,0,asked.length()){
			int now = BSearch(curr, ((int)asked[i] - 65), 0, states[((int)asked[i] - 65)].size()-1, states);
			if( now == -1){
				k = 0;
				cout<<"Not matched\n";
				break;
			}
			else{
				if(i == 0)
					first = states[((int)asked[i] - 65)][0];
				if(i==asked.length()-1)
					last = now;
				curr = now + 1;
			}
		}
		if(k)
			cout<<"Matched "<<first<<" "<<last<<"\n";
	}
	return 0;
}
