#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

double area(int x1, int y1, int x2, int y2, int x3, int y3){
    return abs( x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) )/2.0;
}

// use area to determine whether a point lies inside or outside.
bool insideOrOutside(int n, int d, int x, int y){
    double areaRect = area(0, d, d, 0, n-d, n) + area(d, 0, n-d, n, n, n-d); // area of rectangle.
    double area1 = area(0, d, d, 0, x, y);
    double area2 = area(0, d, n-d, n, x, y);
    double area3 = area(n-d, n, n, n-d, x, y);
    double area4 = area(n, n-d, d, 0, x, y);
    //cout<<areaRect<<" "<<area1<<" "<<area2<<" "<<area3<<" "<<area4<<endl;
    return (areaRect == (area1 + area2 + area3 + area4));
}

int main(){
    int n,d;
    cin>>n>>d;
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        if(insideOrOutside(n , d, x, y))
            cout<<"YES";
        else
            cout<<"NO";
        cout<<endl;
    }
    return 0;
}
