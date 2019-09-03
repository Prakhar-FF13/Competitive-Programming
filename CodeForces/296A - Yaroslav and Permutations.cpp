#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	bool pos=true;
	for(int i = 0; i < n ; i++){
		int cnt=0;
		for(int j = 0 ; j < n ; j++)
			if(arr[i] == arr[j])
				cnt++;

		if(n-cnt < (cnt-1) )
			pos = false;
	}
	if(pos) cout<<"YES";
	else 	cout<<"NO";
	return 0;
}
