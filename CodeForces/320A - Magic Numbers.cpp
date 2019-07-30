#include<bits/stdc++.h>
using namespace std;

int main(){
    string arr;
    cin>>arr;
    int len = arr.length();
    for(int i = 0 ; i < len ; ){
        if(arr[i] != '1'){
            cout<<"NO";
            return 0;
        }else{
            if(i+2 < len){
                if(arr[i+1] == '4' && arr[i+2] == '4'){
                    i+=3;
                    continue;
                }
            }
            if(i+1 < len){
                if(arr[i+1] == '4'){
                    i+=2;
                    continue;
                }

            }
            i++;
        }
    }
    cout<<"YES";
    return 0;
}
