#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
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
    int N,R,i;
    float dif,min;
    i=1;
    fsi
    while(1){
        scanf("%d%d",&R,&N);
        if(R==0&&N==0)break;
        if(N>=R){
            cout<<"Case "<<i<<": "<<0<<endl;
            i++;
            continue;
        }
        dif=R-N;
        min=dif/N;
        min=ceill(min);
        if(min<=26)cout<<"Case "<<i<<": "<<min<<endl;
        else cout<<"Case "<<i<<": impossible"<<endl;
        i++;
    }
    return 0;
}
