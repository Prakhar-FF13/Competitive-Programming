#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,sx,sy,ex,ey;
    cin>>t>>sx>>sy>>ex>>ey;
    string str;
    cin>>str;
    int i;
    for(i = 0 ; i < t; i++){
        if(str[i] == 'E' && abs(sx+1 - ex) < abs(sx-ex))
            sx += 1;
        else if(str[i] == 'W' && abs(sx-1-ex) < abs(sx-ex))
            sx -=1;
        else if(str[i] == 'N' && abs(sy+1-ey) < abs(sy-ey))
            sy += 1;
        else if(str[i] == 'S' && abs(sy-1-ey) < abs(sy-ey))
            sy -= 1;
        //cout<<sx<<" "<<sy<<"\n";
        if(sx == ex && sy == ey){
            cout<<i+1;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
