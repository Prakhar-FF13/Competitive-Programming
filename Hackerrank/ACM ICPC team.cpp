#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, cnt = 0, max_tpc = 0, temp_cnt = 0;
    cin>>n>>m;
    string s[1005];
    for( int i = 0; i < n; i++ )    cin>>s[i];

    for( int i = 0; i < n; i++ )
        for( int j = i + 1; j < n; j++ ){
            temp_cnt = 0;

            for( int k = 0; k < m; k++ )
                if(  s[i][k] == '1' || s[j][k] == '1' ) temp_cnt++;

           if( temp_cnt == max_tpc ){
                cnt++;
                continue;
            }
            
            if( temp_cnt > max_tpc ){
                max_tpc = temp_cnt;
                cnt = 1;
            }

            
        }

    cout<<max_tpc<<endl<<cnt<<endl;
    return 0;
}

