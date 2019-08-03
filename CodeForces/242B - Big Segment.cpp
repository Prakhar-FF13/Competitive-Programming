#include<bits/stdc++.h>
using namespace std;

int main(){
    int minl=1000000001 ,maxr=-1;
    int n;
    cin>>n;
    int l[n], r[n];
    for(int i = 0 ; i < n ; i++){
        cin>>l[i]>>r[i];
        minl = min(minl, l[i]);
        maxr = max(maxr, r[i]);
    }
    int ind=-1;
    for(int i = 0 ; i < n ; i++){
        bool possible = (l[i] == minl) & (r[i] == maxr);
        if(possible){
            ind = i+1;
            break;
        }
    }
    cout<<ind;
    return 0;
}
