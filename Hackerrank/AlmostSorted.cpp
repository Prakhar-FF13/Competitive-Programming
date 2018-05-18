#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, v[100005], s[100005];

int main() {
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        s[i] = v[i];
    }
    
    sort(s, s+N);    
    vector<int> diff;
    for(int i=0; i<N; i++)
        if(v[i] != s[i])
            diff.push_back(i);    
    
        
    if(diff.size() == 0){
        cout << "yes" << endl;
        return 0;
    }
        
    if(diff.size() == 2 && s[diff[0]] == v[diff[1]] && s[diff[1]] == v[diff[0]]){
        cout << "yes\nswap " << diff[0] + 1 << " " << diff[1] + 1 << endl;
        return 0;
    }

    reverse(v + diff[0], v + diff.back() + 1);
    bool good = true;
    for(int i=0; i<N; i++)
        good &= v[i] == s[i];
    
    if(good) cout << "yes\nreverse " << diff[0] + 1 << " " << diff.back() + 1 << endl;
    else cout << "no" << endl;    
    return 0;
}

