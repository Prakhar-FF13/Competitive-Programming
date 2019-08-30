#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int main(){
    double d, h, v, e;
    cin>>d>>h>>v>>e;
    double volume = 3.1415926 * d * d * h / 4;
    double rain_volume = 3.1415926 * d * d * e / 4;
    if(rain_volume >= v){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        printf("%.9lf",volume/(v - rain_volume));
    }
    return 0;
}
