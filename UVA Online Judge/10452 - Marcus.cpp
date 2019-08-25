#include<bits/stdc++.h>
using namespace std;
char board[9][9];
int stx, sty, dtx, dty;
int m,n;
string valid;

bool check(int x, int y){
    if(x<0 || x>=m) return false;
    if(y<0 || y>=n) return false;
    for(int i =0 ; i < valid.length() ; i++)
        if(board[x][y] == valid[i])
            return true;
    if(board[x][y] == '#')
        return true;
    return false;
}

void solve(){
    string str = "";
    while(stx != dtx || sty != dty){
        board[stx][sty] = '.';
        if(str != "") str += " ";
        if(check(stx, sty-1)){
            sty -= 1 ;
            str += "left";
        }
        else if(check(stx, sty+1)){
            sty += 1;
            str += "right";
        }
        else if(check(stx-1, sty)){
            stx -= 1 ;
            str += "forth";
        }
    }
    cout<<str<<endl;
}

int main(){

    int t;
    cin>>t;
    valid = "IEHOVA";
    while(t--){
        cin>>m>>n;
        for(int i = 0 ; i < m ; i++){
            string str;
            cin>>str;
            for(int j = 0 ; j < n ; j++){
                board[i][j] = str[j];
                if(str[j] == '@'){
                    stx = i;
                    sty = j;
                }
                if(str[j] == '#'){
                    dtx = i;
                    dty = j;
                }
            }

        }
        solve();
    }
    return 0;
}
