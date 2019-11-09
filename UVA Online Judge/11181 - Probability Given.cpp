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

// http://www.questtosolve.com/browse.php?pid=11181

int main(){
    RW()
    int n,r,t=1;
    while(cin>>n>>r){
        if(n == 0)
            break;
        string str = "";
        double *arr = new double[n];
        double *p   = new double[n];
        rep(i, 0, n)    arr[i] = 0.0;
        rep(i, 0, n)    cin>>p[i];
        rep(i, 0, n-r)
            str += "0";
        rep(i, 0, r)
            str += "1";
        double probTotal = 0.0;
        do{
            double probNow = 1;
            rep(i, 0, str.length())
                if(str[i] == '1')
                    probNow *= p[i];
                else
                    probNow *= 1-p[i];
            rep(i, 0, str.length()) // if a person bought an item in this permutation increase the probability corresponding to him.
                if(str[i] == '1')
                    arr[i] += probNow;

            probTotal += probNow;
        }while(next_permutation(all(str))); // generate all permutations where r ppl bought an item.

        cout<<"Case "<<t++<<":"<<endl;
        rep(i,0,n)
            printf("%.6lf\n", arr[i]/probTotal); // divide by total r ppl bought permutation probability.
    }
    return 0;
}
