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


bool isPrime(int prime[], int num){
	for(int i=0;i<15 && prime[i] < num;i++)
		if(num % prime[i] == 0)
			return false;
	
	return true;
}
void PrimeRing(int n, vi arr, bool used[], vi curr, int prime[]){
	if(curr.size() == n){

		if( isPrime(prime, curr[curr.size()-1] + curr[0]) )
			for(int i = 0;i<n;i++){
				cout<<curr[i];
				if(i!=n-1)
					cout<<" ";
			}
		else
			return;
		
		cout<<"\n";
	}
	
	for(int i=1;i<n;i++){
		if( used[i] == false && isPrime( prime, curr[curr.size()-1] + arr[i]) ) {
			used[i] = true;
			curr.pb(arr[i]);
			PrimeRing(n, arr, used, curr, prime);
			curr.pop_back();
			used[i] = false;
		}
	}
}
int main()
{
	//RW()
	int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int n;
	int c = 1;
	while(cin>>n){
		if(c>1)
			cout<<"\n";
		vi arr(n);
		bool used[n];
		memset(used, false, sizeof(used));
		rep(i,0,n)
			arr[i]=i+1;
		vi curr;
		curr.pb(1);
		used[0] = true;
		cout<<"Case "<<c++<<":\n";
		PrimeRing(n, arr, used, curr, prime);

	}
	return 0;
}
