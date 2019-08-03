#include<bits/stdc++.h>
using namespace std;

int main(){
    string g1,g2;
    cin>>g1;
    cin>>g2;
    if(g1.length() != g2.length()){
        cout<<"NO"; return 0;
    }else if(g1.length() ==1 && g2.length()==1){
        if(g1[0] == g2[0]) cout<<"YES";
        else cout<<"NO";
    }else{
        int ind1=-1, ind2=-1, cntiff=0;
        for(int i =0 ; i < g1.length() ; i++){
            if(g1[i] != g2[i]){
                cntiff++;
                if(ind1==-1) ind1 = i;
                else if(ind2==-1) ind2 = i;
            }
        }
        if(cntiff == 0){cout<<"YES"; return 0;}
        else if(cntiff != 2){cout<<"NO"; return 0;}
        swap(g1[ind1], g1[ind2]);
        if(g1[ind1] == g2[ind1] && g1[ind2] == g2[ind2])
            cout<<"YES";
        else
            cout<<"NO";
    }
    return 0;
}
