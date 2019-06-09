#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long denoms[1000] = {0};
	long long primes[] = {2,3,5,7,11,13,17,19};
	int numsubs = (1<<8)-1;
	long long d=0;
	for(int i = 1; i <= numsubs; i++){
		int setbitcnt = __builtin_popcount(i);
		int temp = i;
		int k = 0;
		long long mul = 1;
		while(temp){
			if(temp & 1)
				mul *= primes[k];
			k++;
			temp = temp>>1;
		}
		if(setbitcnt & 1)
			denoms[d] = 1*mul;
		else
			denoms[d] = -1*mul;
		d++;
	}
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long ans = 0;
		for(int i = 0 ; i < d ; i++)
			ans += n/denoms[i];
		cout<<ans<<endl;
	}
	return 0;
}
