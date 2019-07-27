#include<bits/stdc++.h>
using namespace std;

int main(){
    int mat[3][3], arr[3][3];
    for(int i = 0 ; i  <3 ; i++){
        for(int j = 0; j < 3 ; j++){
            cin>>arr[i][j];
            mat[i][j] = 1;
            arr[i][j] %= 2;
        }
    }
    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    for(int i = 0 ; i  <3 ; i++)
        for(int j = 0; j < 3 ; j++)
            if(arr[i][j]){
                mat[i][j] = abs(mat[i][j] - 1);
                for(int k = 0; k < 4; k++){
                    int newx = i + dx[k];
                    int newy = j + dy[k];
                    if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3)
                        mat[newx][newy] = abs(mat[newx][newy] - 1);
                }
            }
    for(int i = 0 ; i  <3 ; i++){
        for(int j = 0; j < 3 ; j++)
            cout<<mat[i][j];
        cout<<"\n";
    }
    
    

    return 0;
}