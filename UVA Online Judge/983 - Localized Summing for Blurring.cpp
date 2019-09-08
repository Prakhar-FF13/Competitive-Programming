#include<bits/stdc++.h>
using namespace std;
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);

int main(){
    int n,m;
    //RW()
    bool first = true;
    while(cin>>n>>m){
        if(!first) cout<<endl;
        long long arr[n+1][n+1];
        for(int i = 0 ; i < n+1; i++)
            arr[i][0] = arr[0][i] = 0;
        for(int i = n ; i >= 1 ; i--){
            for(int j = 1 ; j <= n ; j++){
                cin>>arr[i][j];
            }
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                arr[i][j] += arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
            }
        }
        /*cout<<endl;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
        long long ansmat[n-m+1+1][n-m+1+1];
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                int endx = i + m - 1;
                int endy = j + m - 1;
                if(endx <= n && endy <= n){
                    ansmat[i][j] = arr[endx][endy];
                    ansmat[i][j] -= arr[endx][j-1];
                    ansmat[i][j] -= arr[i-1][endy];
                    ansmat[i][j] += arr[i-1][j-1];
                }
                else
                    break;
            }
        }
        long long sum = 0;
        for(int i = n-m+1 ; i >= 1; i--){
            for(int j = 1; j <= n-m+1 ; j++){
                cout<<ansmat[i][j]<<endl;
                sum += ansmat[i][j];
            }
        }
        cout<<sum<<endl;
        first = false;
    }
    return 0;
}
