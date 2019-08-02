#include<iostream>
    #include<cstdio>
    #include<cmath>
    #include<cstdlib>
    #include <algorithm>
    #include<cstring>
    #include<string>
    using namespace std;

    int main()
    {
        int n, a = 0;
        int i, w;
        scanf("%d", &n);
        for (i = 0; i<n; i++)
        {
            scanf("%d", &w);
            if (w == 100)
            {
                a++;
            }
        }
        if (a % 2 == 1 || (n % 2 == 1 && a == 0))
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
        return 0;
    }
