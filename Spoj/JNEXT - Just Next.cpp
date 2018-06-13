#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0 ; i < n ; i++)
			cin>>arr[i];
		int k = n-2;
		while(k>=0 && arr[k] >= arr[k+1])
			k--;
		if(k < 0){
			cout<<-1<<"\n";
		}
		else{
			int j = n-1;
			while(arr[k] >= arr[j])
				j--;
			swap(arr[k], arr[j]);
			sort(arr + k + 1, arr + n);
			for(int i = 0 ; i < n ; i++)
				cout<<arr[i];
			cout<<"\n";
		}
	}
}
