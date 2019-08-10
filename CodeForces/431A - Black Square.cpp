#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[5];
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    string str;
    int calories = 0;
    cin>>str;
    for(int i = 0 ; i < str.length() ; i++)
        calories += a[int(str[i] - '0')];
    cout<<calories;
    return 0;
}
