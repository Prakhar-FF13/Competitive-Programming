#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,q,i,j,mn,mx;
    cin>>n;
    int a[n]= {0};
    for(i=0; i<n; i++)
        cin>>a[i];
    cin>>q;
    int b[q]= {0};
    for(i=0; i<q; i++)
        cin>>b[i];
    for(i=0; i<q; i++)
    {
        mn=lower_bound(a,a+n,b[i])-a-1;
        mx=upper_bound(a,a+n,b[i])-a;
        if(mn>0&&mx>=n)
        {
            printf("%d X\n",a[mn]);
        }
        else if(mn>=0&&mn<n&&mx>=0&&mn<n)
        {
            cout<<a[mn]<<" "<<a[mx]<<endl;
        }
        else if(mn<0&&mx<n)
        {
            printf("X %d\n",a[mx]);
        }
        else
        {
            printf("X X\n");
        }
    }
    return 0;
}
