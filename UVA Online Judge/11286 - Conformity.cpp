#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>
#include<tuple>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

int main(){
	
	int n;

	while(cin>>n and n){

		int maximo=0;

		map <vector<int>, int> frosh;
		vector <int> arr(5);
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 5 ; j++)
			{
				cin>>arr[j];
			}

			sort(arr.begin(), arr.end());

			if(frosh.count(arr)==1){
				frosh[arr]++;
			}
			else{
				frosh[arr]=1;
			}

		}

		map<vector<int>, int>::iterator i;

		for (i = frosh.begin(); i != frosh.end(); ++i)
		{
			if((i->second)>maximo)
				maximo= i->second;
		}

		int cont=0;

		for (i = frosh.begin(); i != frosh.end(); ++i)
		{
			if((i->second)==maximo)
				cont++;
				
		}
		maximo= maximo*cont;
		

		cout<<maximo<<'\n';

		frosh.clear();

	}

	return 0;
}