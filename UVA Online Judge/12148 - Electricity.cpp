#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

bool isLeapYear(int y)
{
    return ((y%4==0 && y%100!=0) || y%400==0);
}

bool isPrevious(int date, int month, int year, int pdate, int pmonth, int pyear)
{
    if(date>1)
    {
        if(pdate+1==date && month==pmonth && year==pyear) return true;
    }
    else if(year==pyear+1 && month==1 && pmonth==12 && pdate==31) return true;
    else if(year==pyear && month==pmonth+1)
    {
        if(month==2 && pdate==31) return true;
        if(month==3 && pdate==28+isLeapYear(year)) return true;
        if(month==4 && pdate==31) return true;
        if(month==5 && pdate==30) return true;
        if(month==6 && pdate==31) return true;
        if(month==7 && pdate==30) return true;
        if(month==8 && pdate==31) return true;
        if(month==9 && pdate==31) return true;
        if(month==10 && pdate==30) return true;
        if(month==11 && pdate==31) return true;
        if(month==12 && pdate==30) return true;
    }
return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, kk=1, n,kwh, date, pdate, month, pmonth, year, pyear, pkwh;
    string s;
    char ch;
    while(cin>>n && n)
    {
        int cnt=0, tot=0;
        for(int i=0;i<n;i++)
        {
            cin>>date>>month>>year>>kwh;
            if(i)
            {
                if(isPrevious(date, month, year, pdate, pmonth, pyear))
                {
                    cnt++, tot+=(kwh-pkwh);
                }

            }
            pdate=date, pmonth=month, pyear=year, pkwh=kwh;
        }
        cout<< cnt << " "<<tot<<"\n";
    }
return 0;
}
