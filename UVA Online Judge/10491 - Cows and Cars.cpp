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

int main(){
    //RW()
    int nCows, nCars, nShows;
    while(cin>>nCows>>nCars>>nShows){
        double totalDoors = nCows+nCars;
        double probCow = nCows/totalDoors;
        double probCar = nCars/totalDoors;

        // a. if chosen one had a cow then prob of car = (nCars)/remain
        // b. if chosen one had a car then prob of car = (nCars-1)/remain.
        double remain = totalDoors - (nShows+1); // nCows shown + i do not take current door.
        double caseA = nCars/remain;
        double caseB = (nCars-1)/remain;

        double totalProb = probCow*caseA + probCar*caseB;

        printf("%.5f\n", totalProb);
    }
    return 0;
}
