#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int a = sqrt(x * z / y + 0.5);
    int b = sqrt(x * y / z + 0.5);
    int c = sqrt(y * z / x + 0.5);
    cout<<(a+b+c)*4<<endl;
    return 0;
}
