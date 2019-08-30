#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    set<char> diag, non_diag;
    for(int i = 0; i  < n ; i++){
        for(int j =0 ; j <  n ; j++){
            char c;
            cin>>c;
            if(i == j || i + j == (n-1))
                diag.insert(c);
            else
                non_diag.insert(c);

        }
    }
    if(diag.size() == 1 && non_diag.size() == 1){
        if((*diag.begin()) != (*non_diag.begin()))
            cout<<"YES";
        else
            cout<<"NO";
    }else{
        cout<<"NO";
    }

    return 0;
}
