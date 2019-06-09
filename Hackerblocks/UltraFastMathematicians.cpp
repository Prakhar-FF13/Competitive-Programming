#include <bits/stdc++.h>
using namespace std;

string getans(string s1, string s2){
    for (int i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == s2[i])
        {
            s1[i] = '0';
        }
        else
        {
            s1[i] = '1';
        }
    }
    return s1;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        cout<<getans(s1, s2)<<"\n";
    }

    return 0;
}
