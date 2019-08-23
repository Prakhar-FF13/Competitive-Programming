#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c;
    //freopen("write.txt","w",stdout);
    while(cin>>n>>m>>c){
        if(n ==0 || m == 0)
            break;
        if(n ==8 && m == 8 && c == 0)
            cout<<0<<"\n";
        else if(n == 8 && m == 8 && c == 1)
            cout<<1<<'\n';
        else{
            // c= 1 -> white, c = 0- > black.
            if((n-8 + m-8) % 2 != 0)
                c = 1-c;
            long long ans = 0;
            int total_rows =  n - 8 + 1;
            int half1, half2;
            if(total_rows%2 == 0){
                half1 = half2 = total_rows/2;
            }else{
                half1 = total_rows/2 + 1;
                half2 = total_rows - half1;
            }
            int total_cols = m - 8 + 1;
            int col1, col2;
            col1 = total_cols/2;
            col2 = col1;
            if(total_cols%2 != 0) col1++;
            if(c == 0){
                swap(col1, col2);
            }
            ans += col1 * half1;
            ans += col2 * half2;
            cout<<ans<<"\n";
        }
    }
}
