
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i = 0 ; i < n; i++)
        cin>>arr[i];
   	
    map<long long, long long> m;
    long long arrows = 0;
    for(int i = 0; i < n ; i++){
        if(m[arr[i]] > 0){
            m[arr[i]]--;
            if(arr[i]-1 > 0)
                m[arr[i] - 1]++;
        }else{
            arrows++;
            if(arr[i]-1 > 0)
            	m[arr[i]-1]++;
        }
    }
    cout<<arrows;
    return 0;
}