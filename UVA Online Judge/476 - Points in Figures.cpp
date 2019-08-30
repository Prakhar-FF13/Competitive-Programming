#include<bits/stdc++.h>
using namespace std;

int main(){
    char c;
    vector<tuple<double, double, double, double> > rects;
    while(cin>>c){
        if(c == '*')
            break;
        double x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        rects.push_back(make_tuple(x1, y1, x2, y2));
    }
    double x,y;
    int point = 1;
    while(cin>>x>>y){
        if(x == 9999.9 && y == 9999.9)
            break;
        int figind = -1;
        for(int i = 0 ;i < rects.size() ; i++){
            tuple<double, double ,double, double> pqr = rects[i];
            double x1 = get<0>(pqr);
            double y1 = get<1>(pqr);
            double x2 = get<2>(pqr);
            double y2 = get<3>(pqr);
            if(x > x1 && x < x2){
                if(y < y1 && y > y2){
                    figind = i+1;
                    cout<<"Point "<<point<<" is contained in figure "<<figind<<endl;
                }
            }
            //cout<<x<<" "<<y<<" "<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
        }
        if(figind == -1)
            cout<<"Point "<<point<<" is not contained in any figure"<<endl;
        point++;
    }
    return 0;
}
