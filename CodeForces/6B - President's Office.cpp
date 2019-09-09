#include<bits/stdc++.h>
using namespace std;
set<char> s;
int visited[101][101];
int n,m;
char c;
string str[101];
void solve(int &ans, int i, int j){
    if(i < 0 || i >= n) return;
    if(j < 0 || j >= m) return;
    if(visited[i][j] == 1)  return;
    if(str[i][j] == '.')    return;
    visited[i][j] = 1;
    if(str[i][j] == c){
        solve(ans, i+1, j);
        solve(ans, i, j+1);
        solve(ans, i-1, j);
        solve(ans, i, j-1);
    }else if(s.find(str[i][j]) == s.end()){
            ans++;
            s.insert(str[i][j]);
    }
}

int main(){
    scanf("%d %d %c", &n, &m, &c);
    for(int i = 0 ; i < n  ;i++)
        cin>>str[i];
    /*cout<<endl;
    for(int i = 0 ; i < n  ;i++)
        cout<<str[i]<<endl;*/

    for(int i = 0 ; i < n+1 ; i++)
        for(int j = 0 ; j  < m+1 ; j++)
            visited[i][j] = 0;
    int ans = 0 ;
    for(int i = 0 ; i  <n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(str[i][j] == c){
                solve(ans, i, j);
                cout<<ans;
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
}
