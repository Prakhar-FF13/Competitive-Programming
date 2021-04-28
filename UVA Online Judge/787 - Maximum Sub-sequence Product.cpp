#include<bits/stdc++.h>

using namespace std;

int main()
{

    while(1)
    {
        int mx[200];

        int i=0,n;

        while((cin>>n)&&(n!=-999999))
        {
            mx[i++]=n;
        }

        long sum=1,mxV=-999999;

        for(int j=0;j<i;j++)
        {
            sum=1;
            for(int k=j;k<i;k++)
            {
                sum=sum*mx[k];
            }
            if(mxV<sum)mxV=sum;
        }
        printf("%ld\n",mxV);


    }
    return 0;
}