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
bitset<20000000> p;

map<pii, vi> states;
vi primes;


// goldBach -> Every even number can be written as sum of two primes.
// every no. less than 8 cannot be written as sum of 4 primes, lowest  possible is 8
// for every number above 8 either 2 2 is present as solution or 2 3 is present as solution.
// 2 3 is present if numb is odd subtracting 2 and 3 gives even no.
// 2 2 is present if numb is even.
void goldBach(int num){
    for(int i = 0 ; (i < primes.size()) && (primes[i] <= num) ; i++){
        if(p.test(num - primes[i]) == 1){
            cout<<primes[i]<<" "<<num-primes[i];
            return;
        }
    }
    return;
}

int main(){
    RW()
    p.set();
    p.set(1, 0);
    rep(i, 2, 10000005){
        if(p.test(i) == 1){
            for(int j = i*2 ; j < 10000005; j += i)
                p.set(j, 0);
        }
    }
    rep(i, 2, 10000005)
        if(p.test(i))
            primes.pb(i);

    int num;
    while(cin>>num){
        if(num < 8){ cout<<"Impossible.\n"; continue;}
        if(num&1){
            cout<<"2 3 ";
            num -= 5;
        }else{
            cout<<"2 2 ";
            num -= 4;
        }
        goldBach(num);
        cout<<endl;
    }
    return 0;
}
