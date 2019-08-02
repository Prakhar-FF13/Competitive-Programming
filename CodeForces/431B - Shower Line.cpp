#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[6][6];
ll getHappiness(char *str, int len){
    if(len == 1)
        return 0;
    ll ans = 0;
    for(int i = 0 ; i < len-1 ; i+=2){
        int x = str[i] - '0';
        int y = str[i+1] - '0';
        ans += g[x][y] + g[y][x];
    }
    return ans + getHappiness(str+1, len-1);
}

int main(){
    char *str = new char[5];
    strcpy(str, "12345");

    for(int i = 1 ; i <= 5 ; i++)
        for(int j = 1 ;  j <= 5; j++)
            cin>>g[i][j];
    ll ans = 0;
    do{
        ans = max(ans, getHappiness(str, 5));
    }while(next_permutation(str, str + 5));
    cout<<ans;
    return 0;
}
