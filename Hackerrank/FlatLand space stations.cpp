#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    sort(c.begin(), c.end());
    vector<int> dist(n);
    int last = -1000000;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur < m && c[cur] == i) {
            cur++;
            last = i;
        }
        dist[i] = i - last;
    }
    cur = m-1;
    last = 1000000;
    for (int i = n-1; i >= 0; i--) {
        if (cur >= 0 && c[cur] == i) {
            cur--;
            last = i;
        }
        dist[i] = min(dist[i], last - i);
    }
    printf("%d\n", *max_element(dist.begin(), dist.end()));
    return 0;
}

