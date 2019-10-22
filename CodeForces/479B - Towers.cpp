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

    long n, k; scanf("%ld %ld\n", &n, &k);
    std::vector<std::pair<long, long> > heightVec(n);

    for(int p = 0; p < n; p++){
        long temp; scanf("%ld", &temp); heightVec[p].first = temp;
        heightVec[p].second = p + 1;
    }

    std::vector<std::pair<long, long> > moves;
    long instability(0);

    for(int q = 0; q < k; q++){
        sort(heightVec.begin(), heightVec.end());
        if(heightVec[n - 1].first <= heightVec[0].first + 1){break;}
        --heightVec[n - 1].first; ++heightVec[0].first;
        moves.push_back(std::pair<long, long>(heightVec[n - 1].second, heightVec[0].second));
    }

    sort(heightVec.begin(), heightVec.end());
    printf("%ld %ld\n", heightVec[n - 1].first - heightVec[0].first , moves.size());
    for(int p = 0; p < moves.size(); p++){
        printf("%ld %ld\n", moves[p].first, moves[p].second);
    }

    return 0;
}