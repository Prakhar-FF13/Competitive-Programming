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

#define UL 20000000

bitset<UL> p;

void setPrimes(){
    p.flip();
    p.reset(0);
    p.reset(1);

    for(long long i = 2; i <= sqrt(UL); i++)
        if(p.test(i)){
            for(long long j = i + i; j < UL; j += i)
                p.reset(j);
        }
}
int main(){
  // freopen("input.txt", "r", stdin);
    int N;
    setPrimes();
    vector< int> twins;



    for(int i = 2; i < UL - 2 ; i++)
        if(p.test(i)){
            if(p.test(i + 2))
            twins.push_back(i);
        }

    while(scanf("%d", &N) == 1){
        N--;
        printf("(%d, %d)\n", twins[N], twins[N]+2);
    }


}
