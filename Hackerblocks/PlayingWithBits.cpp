#include<bits/stdc++.h>
using namespace std;

int findsetbits(int number){
	int cnt = 0;
	while(number > 0){
		number = number&(number-1);
		cnt++;
	}
	return cnt;
}

int main() {
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans = 0;
		for(int i = a; i <= b ; i++)
			ans += findsetbits(i);
		cout<<ans<<endl;
	}
	return 0;
}
