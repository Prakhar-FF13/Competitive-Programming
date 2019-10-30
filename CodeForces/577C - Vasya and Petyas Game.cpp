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
bitset<1005> p;
vi primes;
int n;
unordered_map<int, int> highestPowerOfPrimes;
void generatePrimes(){
    p[0] = 1;
    p[1] = 1;
    rep(i, 2, n+1){
        if(p[i] == 0){
            primes.pb(i);
            for(int j = i*2;  j < n+1; j+=i)
                p.set(j, 1);
        }
    }
}

void generatePowers(){
    rep(i, 2, n+1){
        int t = i;
        rep(j, 0, primes.size()){
            int pr = primes[j];
            if(pr > t)  break;
            int power = 0;
            while(t%pr == 0){
                t /= pr;
                power++;
            }
            if(highestPowerOfPrimes[pr] < power)
                highestPowerOfPrimes[pr] = power;
        }
        if(t != 1)
            if(highestPowerOfPrimes[t] < 1)
                highestPowerOfPrimes[t] = 1;
    }
}

int main(){
    cin>>n;
    // calculate highest power of prime numbers we have in all numbers from 2 to n.
    // every number in prime power is in our answer.
    generatePrimes();
    generatePowers();
    vi ans;
    for(auto it = highestPowerOfPrimes.begin(); it != highestPowerOfPrimes.end(); it++){
        int power = it->second;
        rep(i, 1, power+1){
            ans.pb(pow(it->first, i));
        }
    }
    cout<<ans.size()<<endl;
    rep(i, 0, ans.size())
        cout<<ans[i]<<" ";
    return 0;
}
