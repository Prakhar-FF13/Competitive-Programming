#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<numeric>
#include<functional>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back

int main()
{
    int s,t1,t2,x1,x2,p,d;
    scanf("%d%d",&t1,&t2);
    scanf("%d%d",&p,&d);
    int dix=abs(x2-x1);
    int time1=dix*t2;
    int time2;
    if(d==1)
    {
        if(p<=x1&&x1<x2)
            time2=(x2-p)*t1;
        else if(x1<x2)
            time2=(s-p+s+x2)*t1;
        else if(x2<x1)
            time2=(s-p+s-x2)*t1;
    }
    else if(d==-1)
    {
        if(p>=x1&&x2<x1)
            time2=(p-x2)*t1;
        else if(x2<x1)
            time2=(p+s+s-x2)*t1;
        else if(x1<x2)
            time2=(p+x2)*t1;
    }
    if(time2>time1)
        printf("%d\n",time1);
    else
        printf("%d\n",time2);
	return 0;
}