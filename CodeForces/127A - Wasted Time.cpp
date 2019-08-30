#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int prevx=-1000, prevy =-1000;
    double dist = 0;
    for(int i = 0 ; i < n ; i++){
        double x,y;
        cin>>x>>y;
        if(prevx != -1000){
            dist += (sqrt(pow(x - prevx, 2) + pow(y - prevy, 2))/50);
        }
        prevx = x;
        prevy = y;
    }
    printf("%.9lf", dist*k);
    return 0;
}
