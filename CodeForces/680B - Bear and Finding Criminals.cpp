#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a;
    cin>>n>>a;
    a--;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int left = a-1, right = a+1;
    int cnt = (arr[a] == 1);
    while(left >= 0 && right < n){
        if(arr[left] == 1 && arr[right] == 1) cnt+=2;
        left--;
        right++;
    }
    while(left >= 0){
        cnt += (arr[left] == 1);
        left--;
    }
    while(right < n){
        cnt += (arr[right] == 1);
        right++;
    }
    cout<<cnt;
    return 0;
}
