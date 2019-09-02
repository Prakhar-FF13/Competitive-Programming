#include<bits/stdc++.h>
using namespace std;
int r1,r2,c1,c2,d1,d2;

bool OK(int a, int b, int c, int d){
    if(a + b != r1) return false;
    if(a + d != d1) return false;
    if(a + c != c1) return false;
    if(b + d != c2) return false;
    if(b + c != d2) return false;
    if(c + d != r2) return false;

    return true;
}

int main(){

    cin>>r1>>r2;
    cin>>c1>>c2;
    cin>>d1>>d2;

    for(int a = 1; a <= 9 ; a++)
        for(int b = 1; b <= 9 ; b++)
            for(int c = 1; c <= 9 ; c++)
                for(int d = 1; d <= 9 ; d++){
                    if(a!=b && b!=c && c!=d && a!=c && a!=d && b!=d)
                        if(OK(a,b,c,d)){
                            cout<<a<<" "<<b<<endl;
                            cout<<c<<" "<<d;
                            return 0;
                        }
                }
    cout<<-1;
    return 0;
}
