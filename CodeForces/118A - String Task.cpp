#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    for(int i = 0; i < str.length() ; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            int x = str[i] - 'A';
            str[i] = (x + 'a');
        }
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
            continue;
        else{
            cout<<"."<<str[i];
        }
    }
    return 0;
}
