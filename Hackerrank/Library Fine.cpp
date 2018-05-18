#include <iostream>
using namespace std;
int main()
{
	int ds,ms,ys,dd,md,yd;
	cin>>ds>>ms>>ys;
	cin>>dd>>md>>yd;
	int fine=0;
    if(ys>yd)
		fine+=(10000);
    else if(ms>md && ys>=yd)
		fine+=(500*(ms-md));
	else if(ds>dd && ms>=md && ys>=yd)
		fine+=(15*(ds-dd));
	
	
		
	cout<<fine;
	return 0;
}
