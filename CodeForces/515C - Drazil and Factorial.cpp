#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
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
int n;
string a;

int twoPow, threePow, fivePow, sevenPow;

void increasePowCount(int num){
    int numb[] = {2, 3, 5, 7};
    rep(i, 0, 4){
        int pr = numb[i];
        int cnt = 0;
        while(num%pr == 0){
            cnt++;
            num/=pr;
        }
        if(pr == 2) twoPow += cnt;
        else if(pr == 3) threePow += cnt;
        else if(pr == 5) fivePow += cnt;
        else             sevenPow += cnt;
    }
}

int main(){
    cin>>n;
    cin>>a;
    twoPow=0, threePow=0, fivePow=0, sevenPow=0;
    rep(i, 0, n){
        int num = a[i] - '0';
        if(num == 0 || num == 1)    continue;
        rep(k, 2, num+1)
            increasePowCount(k);
    }
    rep(i, 0, sevenPow){
        cout<<7;
        fivePow--;
        threePow -= 2;
        twoPow -= 4;
    }
    rep(i, 0, fivePow){
        cout<<5;
        threePow--;
        twoPow -= 3;
    }
    rep(i, 0, threePow){
        twoPow--;
        cout<<3;
    }
    rep(i, 0, twoPow)   cout<<2;
    return 0;
}
