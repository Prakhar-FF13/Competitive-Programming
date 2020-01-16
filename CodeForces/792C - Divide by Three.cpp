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
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f

int judge(string str) {
    int sum = 0;
    for (auto x : str)
        sum = (sum + x - '0') % 3;
    return sum | !str.size();
}
void removelead0(string& str) {
    while ((*str.begin()) == '0' && str.size() > 1)
        str.erase(str.begin());
}
int main(void) {
    string str, str1, str2;
    cin >> str;
    int reminder = judge(str), reminder2 = 3 - reminder, t1 = 1, t2 = 2;
    str1 = str2 = str;
    for (int i = (int)str.size() - 1; i >= 0; i--) {
        if ((str[i] - '0') % 3 == reminder && t1)
            str1.erase(i, 1), --t1;
        if ((str[i] - '0') % 3 == reminder2 && t2)
            str2.erase(i, 1), --t2;
    }
    t1 = judge(str1), t2 = judge(str2), removelead0(str1), removelead0(str2);
    if (t1 && t2)
        return 0 * puts("-1");
    if ((str1.size() > str2.size() && (!t1)) || t2)
        str2 = str1;
    cout << str2 << endl;
    return 0;
}