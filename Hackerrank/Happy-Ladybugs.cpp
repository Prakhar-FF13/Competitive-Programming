#include <bits/stdc++.h>
#include<assert.h>

using namespace std;

int arr[30];

void solution() {

    int test, n;
    string str;
    bool empty_cell, flag;

    cin>>test;
    assert(test>0 && test<=100);

    for(int t=1; t<= test; t++)
    {
        memset(arr,0,sizeof(arr));
        empty_cell = false;
        flag = true;

        cin>>n;
        assert(n>0 && n<=100);
        cin>>str;
        assert(str.size() == n);

        for(int i=0; i<n; i++)
        {
            assert((str[i]>='A' && str[i]<='Z') || str[i]=='_');
            if(str[i]>='A' && str[i]<='Z')
                arr[str[i]-'A']++;
            else
            {
                empty_cell = true;
            }

        }

        if(empty_cell)
        {
            for(int i=0; i<26; i++)
            {
                if(arr[i] == 1)
                {
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(!((i-1>=0 && str[i-1]==str[i]) || (i+1<n && str[i+1]==str[i])))
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

int main () {

        solution();

    return 0;
}
