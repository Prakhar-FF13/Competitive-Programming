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
	int one=1;
	while(1){
		int k;
		cin>>k;
		if(k==0)
			break;
		int arr[k];
		for(int i=0;i<k;i++){
			cin>>arr[i];
		}
		if(one>1)
			cout<<"\n";
		one++;
		for(int i=0;i<k-5;i++){
			for(int j=i+1;j<k-4;j++){
				for(int q=j+1;q<k-3;q++){
					for(int l=q+1;l<k-2;l++){
						for(int m=l+1;m<k-1;m++){
							for(int n=m+1;n<k;n++){
								cout<<arr[i]<<" "<<arr[j]<<" "<<arr[q]<<" "<<arr[l]<<" "<<arr[m]<<" "<<arr[n]<<"\n";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
