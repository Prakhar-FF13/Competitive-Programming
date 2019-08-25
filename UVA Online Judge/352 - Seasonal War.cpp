#include<bits/stdc++.h>
using namespace std;

int movx[4], movy[4];
int arr[30][30];
int n;

bool check(int i, int j){
    if(i < 0 || i >= n)
        return false;
    if(j < 0 || j >= n)
        return false;

    return true;
}

void floodfill(int x, int y){
    arr[x][y] = 0;
    for(int i = 0 ; i < 4; i++)
        for(int j = 0 ; j < 4 ; j++){
            int newx = x + movx[i];
            int newy = y + movy[j];
            if(check(newx, newy) && arr[newx][newy] == 1)
                floodfill(newx, newy);
        }
}

int main(){
    movx[0] = -1;movx[1] = 1;movx[2] = 0;movx[3] = 0;
    movy[0] = 0;movy[1] = 0;movy[2] = 1;movy[3] = -1;
    int cnt=1;
    while(cin>>n){
        for(int i = 0 ; i < n ; i++){
            string str;
            cin>>str;
            for(int j = 0 ; j < n ; j++)
                arr[i][j] = str[j] - '0';
        }

        int ans=0;
        for(int i = 0 ; i < n ; i++)
            for(int  j = 0;  j < n ; j++)
                if(arr[i][j] == 1){
                    floodfill(i, j);
                    ans++;
                }
        cout<<"Image number "<<cnt<<" contains "<<ans<<" war eagles."<<endl;
        cnt++;
    }
    return 0;
}
