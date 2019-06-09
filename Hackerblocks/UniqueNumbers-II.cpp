#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	int ans = 0 , x = 0, y = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
		ans ^= arr[i];
	}
	int mask = (ans & (~(ans - 1)));
	for(int i = 0 ; i < n ; i++)
		if(mask & arr[i])
			x ^= arr[i];
		else
			y ^= arr[i];
	int fnum = min(x,y);
	int snum = max(x,y);
	cout<<fnum<<" "<<snum;
	return 0;
}
