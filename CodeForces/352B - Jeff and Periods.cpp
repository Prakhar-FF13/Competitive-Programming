#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    int last_ind[100005];
    int num_d[100005];
    for(int i = 0 ; i < 100005 ;i++)
        last_ind[i] = -1, num_d[i] = -1;
    for(int i = 1 ; i <= n ; i++){
        cin>>arr[i];
        if(num_d[arr[i]] == -2)
            continue;

        if(last_ind[arr[i]] == -1){
            last_ind[arr[i]] = i;
            num_d[arr[i]] = 0;
        }else if(num_d[arr[i]] == 0){
            num_d[arr[i]] = i-last_ind[arr[i]];
            last_ind[arr[i]] = i;
        }else{
            if(i-last_ind[arr[i]] == num_d[arr[i]])
                last_ind[arr[i]] = i;
            else
                num_d[arr[i]] = -2;
        }
    }
    int cnt=0;
    for(int i = 1; i <100005 ;i++)
        if(num_d[i] >= 0)
            cnt++;
    cout<<cnt<<"\n";
    for(int i = 1; i<100005 ; i++)
        if(num_d[i] >= 0)
            cout<<i<<" "<<num_d[i]<<"\n";
    return 0;
}
