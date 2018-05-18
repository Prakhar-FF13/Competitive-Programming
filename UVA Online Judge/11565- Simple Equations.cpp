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

int main(){
	//RW()
	int a,b,c;
	tt(){
		cin>>a>>b>>c;
		bool sol=false;
		int cnt=0;
		rep(i,-100,100){
			if(sol==true)
				break;
			rep(j,-100,100){
				if(sol==true)
					break;
				if(i==j)
					continue;
				rep(k,-100,100){
					if(k==j || k==i)
						continue;
					if((i+j+k)==a && (i*j*k)==b && (i*i+j*j+k*k)==c){
						cout<<i<<" "<<j<<" "<<k<<"\n";
						cnt++;
						sol=true;
						break;
					}
				}
			}
		}
		if(cnt==0){
			cout<<"No solution.\n";
		}
	}
	return 0;
}
