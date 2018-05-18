#include <iostream>
using namespace std;

int main()
    {
    long long int count=1,number=3;
    long long int t,time=3;
    cin>>t;
    while(time < t)
        {
        time=number*2+time;
        number=number*2;
    }
    while(time!=t)
        {
            count++;
            time--;
    }
    cout<<count<<endl;
    return 0;
}
