#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <functional>
#include <numeric>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define PI 2*acos(0.0)
#define MAX3(a,b,c) max(a,max(b,c))
#define MIN3(a,b,c) min(a,min(b,c))
#define MAX   10000007
#define INF   1<<30 	//infinity value
#define EPS   1e-9
#define MOD   1000000007


int main()
{
    //input;
    int tc,cn,m,n,i,j;
    string str1[1501],str2[1501],con,c;

     map<string,int> mp;

    scanf("%d",&tc);


    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d %d",&m,&n);
        getchar();

        for(i=0;i<m;i++)
         getline(cin,str1[i]);

        for(j=0;j<n;j++)
            getline(cin,str2[j]);

        int cnt=0;

       mp.clear();

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                con = str1[i]+str2[j];

                if(mp[con]==0)
                {
                    mp[con]=1;
                    cnt++;
                }
            }
        }

          printf("Case %d: %d\n",cn,cnt);

    }

	return 0;
}