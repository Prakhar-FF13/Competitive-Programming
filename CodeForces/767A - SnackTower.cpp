#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int found[n+1];
    int t = n;
    for(int i = 0 ; i < n +1 ; i++) found[i] = 0;
    for(int i = 0 ; i < n ; i++){
        int snk;
        cin>>snk;
        found[snk] = 1;
        if(snk == t){
            while(found[t] == 1){
                cout<<t<<" ";
                t--;
            }
        }
        cout<<"\n";
    }
    return 0;
}
