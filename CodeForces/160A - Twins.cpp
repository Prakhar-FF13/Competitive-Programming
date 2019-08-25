#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr.rbegin(), arr.rend());
    int i = 0 ;
    int len = arr.size();
    sum /= 2;
    int cnt=0;
    int selfish=0;
    while(i < len){
        if(selfish > sum)
            break;
        selfish += arr[i];
        cnt++;
        i++;
    }
    cout<<cnt;
    return 0;
}
