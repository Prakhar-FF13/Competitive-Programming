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
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
#define PB push_back
#define pi acos(-1.0)
#define eps 1e-9

map<int,int>indegree;
map<int,int>taken;
vector<int>depends[110];
vector<int>result;

int main()
{
map<string,int>index;
map<int,string>index2;
int num,match,i,j,k,indx,cs=1;
string s,s2;
while(cin>>num)
{
   indx=0;
   for(i=1;i<=num;i++)
   {
       cin>>s;
        index[s]=++indx;
        index2[indx]=s;
   }
   cin>>match;
   for(i=1;i<=match;i++)
   {
       cin>>s>>s2;
       indegree[index[s2]]++;
       depends[index[s]].PB(index[s2]);
   }

for(i=1;i<=num;i++)
    for(j=1;j<=num;j++)
        if(!indegree[j] && !taken[j])
        {
            taken[j]=1;
            result.PB(j);
            for(k=0;k<depends[j].size();k++)
            indegree[depends[j][k]]--;
            break;
        }
cout<<"Case #"<<cs<<": Dilbert should drink beverages in this order: ";
for(i=0;i<result.size()-1;i++)
cout<<index2[result[i]]<<" ";
cout<<index2[result[i]]<<"."<<endl<<endl;
indegree.clear();
taken.clear();
result.clear();
for(i=1;i<=num;i++)
depends[i].clear();
cs++;
}

return 0;
}
