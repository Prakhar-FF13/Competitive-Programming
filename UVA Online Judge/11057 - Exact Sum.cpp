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

int ExactSum(int key, int low, int high, int arr[])
{
	int mid;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(key == arr[mid])
			return arr[mid];
		else if( key > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main()
{
	int n;
	
	while(cin>>n)
	{
		int books[n];
		rep(i,0,n)
			cin>>books[i];
		
		int currmin = (int)(1e9);
		int m;
		cin>>m;
		int one,sec;
		sort(books, books+n);
		rep(i,0,n){
			int trash = ExactSum(m - books[i], 0, n-1, books);
			if(trash != -1 && abs(trash - books[i]) < currmin){
				one = min(trash, books[i]);
				sec = max(trash, books[i]);
				currmin = sec-one;
			}
		}
		cout<<"Peter should buy books whose prices are "<<one<<" and "<<sec<<".\n\n";
	}
	return 0;
}
