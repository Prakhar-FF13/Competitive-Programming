/*
    Tags - Good overlapping intervals problem. Greedy
    just sorting and making radar on further wont work.
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n, i;
pair<double, double> island[1005];

int solve() {
    double r = -1e9;
    int cnt = 0;

    sort(island, island+n);
    i = 0;
    while(i < n) {
        while(i < n && island[i].first <= r) {
            r = r < island[i].second ? r : island[i].second;
            ++i;
        }
        ++cnt;
        r = island[i].second;
    }

    return cnt-1;
}

int main(void)
{
    double x, y, d;
    int flag, cas = 0;

    while(scanf("%d %lf", &n, &d) && n) {
        flag = 0;
        for(i = 0; i < n; ++i) {
            scanf("%lf %lf", &x, &y);

            if(y > d) flag = 1;
            else {
                island[i].first = x - sqrt(d*d - y*y);
                island[i].second = x + sqrt(d*d - y*y);
            }
        }
        printf("Case %d: %d\n", ++cas, flag ? -1 : solve());
    }


    return 0;
}