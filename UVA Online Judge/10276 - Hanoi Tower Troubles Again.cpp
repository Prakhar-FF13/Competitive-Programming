#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007




int main()
{
    int n,t,i,j,sqrt_sum;
    bool used;
    cin>>t;
    while(t--)
    {
        cin>>n;
        stack<int>peg[55];
        for(i=1;;i++)
        {
            used=false;
            for(j=0;j<n;j++)
                if(!peg[j].empty())
                {
                    sqrt_sum=sqrt(peg[j].top()+i);
                    if((peg[j].top()+i)==(sqrt_sum*sqrt_sum))
                        {
                            peg[j].push(i);
                            used=true;
                            break;
                        }
                }

                else
                {
                    peg[j].push(i);
                    used=true;
                    break;
                }
            if(!used)
                break;

        }
        cout<<i-1<<endl;
    }
return 0;
}