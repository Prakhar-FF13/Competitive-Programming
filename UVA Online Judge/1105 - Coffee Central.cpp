/*
    Tags - 2D DP - prefix sum very good problem.
*/
#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
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
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define repit(a)      for(auto it = a.begin(); it != a.end(); it++)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;for(int xt = 1; xt <= t; xt++)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

void rotates(int &x, int &y, int dy) {
    int newX = x + dy - 1 - y;
    int newY = x + y;
    x = newX;
    y = newY;
}

int main () {
    RW()
    fsi

    int dx, dy, n, q, xt = 1;
    while(cin>>dx>>dy>>n>>q, dx) {
        // tranformed matrix dimensions are (m+n-1) x (m+n-1), (after rotation 45 degrees counterclockwise);
        int city[dx + dy][dx + dy];
        ms(city, 0 ,sizeof(city));

        // transform the coordinates and fill the values.
        rep(i, 0, n) {
            int x, y;
            cin>>x>>y;
            x--,y--; 
            rotates(x, y, dy);   
            city[x][y] = 1;
        }

        // prefix sum dp on transformed matrix.
        rep(i, 0, dx+dy)
            rep(j, 0, dx+dy) {
                if (i > 0)  city[i][j] += city[i-1][j];
                if (j > 0)  city[i][j] += city[i][j-1];
                if (i > 0 && j > 0) city[i][j] -= city[i-1][j-1];
            }

        // queries.
        cout<<"Case "<<xt++<<":"<<endl;

        while(q--) {
            int m;
            cin>>m;

            int ans = -1, ansX, ansY;

            // use DP values to find answer in transformed matrices.
            rep(i, 0, dx) {
                rep(j, 0, dy) {
                    // making i and j as my center.
                    int cx = i, cy = j;
                    rotates(cx, cy, dy);

                    // use dp to get shops near this center.
                    int subans = 0;
                    int rightEndX = min(cx + m, dx+dy-1),
                        rightEndY = min(cy + m, dx+dy-1);

                    int leftEndX = max(cx - m, 0),
                        leftEndY = max(cy - m, 0);

                    // bottom rightmost reachable cell.
                    subans += city[rightEndX][rightEndY];

                    if (leftEndX > 0)   subans -= city[leftEndX-1][rightEndY];
                    if (leftEndY > 0)   subans -= city[rightEndX][leftEndY-1];
                    if (leftEndX > 0 && leftEndY > 0)   subans += city[leftEndX-1][leftEndY-1];

                    if (subans > ans || (subans == ans && j < ansY)) {
                        ans = subans,
                        ansX = i,
                        ansY = j;
                    }
                }
            }

            cout<<ans<<" ("<<ansX+1<<","<<ansY+1<<")"<<endl;
        }
    }

    return 0;
}