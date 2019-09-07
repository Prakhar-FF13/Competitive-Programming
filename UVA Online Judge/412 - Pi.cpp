#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0)
        return a;

    return gcd(b, a%b);
}
int main(){
    int n;
    int arr[52];
    while(cin>>n){
        if(n == 0)  break;
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
        int cnt = 0;
        int total = n * (n-1)/2;
        for(int i = 0 ; i < n ; i ++)
            for(int j = i+1 ; j  < n ; j++){
                int x = gcd(arr[i], arr[j]);
                //cout<<arr[i]<<" "<<arr[j]<<" "<<x<<"\n";
                if(x == 1)
                    cnt++;
            }
        if(cnt == 0) cout<<"No estimate for this data set.\n";
        else printf("%.6f\n", sqrt((6.0 * total)/cnt));
    }
    return 0;
}
