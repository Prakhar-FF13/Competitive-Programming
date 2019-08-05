#include<bits/stdc++.h>
using namespace std;

bool possible(int c[], int i[], int n, int m, int v){
    // all correct solution pass;
    for(int j = 0 ; j < n ; j++)
        if(c[j] > v)    return false;
    // all incorrect solution dont pass;
    for(int j = 0 ; j < m ; j++)
        if(i[j] <= v)   return false;
    // at-least 1 correct pass under system settings;
    for(int j = 0 ; j < n ; j++)
        if(c[j] * 2 <= v)   return true;

    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    int correct[n], incorrect[m];
    int minlim=300, maxlim=-1;
    for(int i = 0 ; i < n ; i++){
        cin>>correct[i];
        minlim = min(minlim, correct[i]);
    }
    for(int i = 0;  i < m ; i++)
        cin>>incorrect[i];
    for(int i = minlim ; i <= 101 ; i++){
        if(possible(correct, incorrect, n, m, i)){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
