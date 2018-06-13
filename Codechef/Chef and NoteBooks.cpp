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

int main(){
	//x = poetry pages, y = number of pages in current notebook, k = money left, n = no. of notebooks, p = pages in notebook.
	//c = cost of notebook
	fsi
	int x,y,k,n,p,c,pagesneeded;
	tt(){
		cin>>x>>y>>k>>n;
		pagesneeded = x - y;
		rep(i,0,n){
			cin>>p>>c;
			if(c <= k && p >= pagesneeded)
				pagesneeded = 0;
		}
		if(x <= y){
			cout<<"LuckyChef\n";
		}
		else{
			if(pagesneeded == 0)
				cout<<"LuckyChef\n";
			else
				cout<<"UnluckyChef\n";
		}
	}
	return 0;
}
