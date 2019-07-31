#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int arr[27];
    for(int i = 0 ; i < 27 ; i++)
        arr[i] = 0;
    for(int i = 0 ; i < str.length() ; i++){
        int x = str[i] - 'a';
        arr[x]++;
    }
    int ply=0;
    while(1){
        int oddcnt=0;
        for(int i = 0 ; i< 27 ; i++)
            if(arr[i]%2==1)
                oddcnt++;
        if(oddcnt <= 1){
            if(ply==0)
                cout<<"First";
            else
                cout<<"Second";
            break;
        }
        //cout<<oddcnt<<"\n";
        bool removed=false;
        for(int i = 0;  i< 27 ; i++)
            if(arr[i]%2==0 && arr[i]!=0){
                arr[i] -= 1;
                removed = true;
                break;
            }
        if(!removed){
            //cout<<ply<<"\n";
            for(int i = 0;  i< 27 ; i++)
                if(arr[i]%2==1){
                    arr[i] -= 1;
                    //cout<<"removed char at: "<<i<<"\n";
                    break;
                }
        }
        ply++;
        ply%=2;
    }
    return 0;
}
