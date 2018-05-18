#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, b, n, i;
        long long int c,d;
        set <int> x;
        cin >> n >> c >> d;
        a = min(c,d);
        b = max(c,d);
        n--;
        for (i = 0; i <= n; i++) {
            x.insert(i * b + (n - i) * a);
        }
        for (auto it:x) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
