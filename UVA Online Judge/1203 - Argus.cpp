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

typedef struct query {
    int id, period, time;

    query(int a, int b) {
        id = a;
        period = b;
        time = b;
    }
} Q;

struct cmp {
    bool operator()(Q const &a, Q const &b) {
        if (a.time == b.time)   return a.id > b.id;
        else                        return a.time > b.time;
    }
};

int main () {
    RW()
    fsi
    string str;
    priority_queue<Q, vector<Q>, cmp> pq;
    while(cin>>str) {
        if (str == "#") break;
        int a,b;
        cin>>a>>b;
        pq.push(*(new Q(a,b)));
    }
    int k;
    cin>>k;
    while(k--)  {
        Q x = pq.top();
        pq.pop();
        cout<<x.id<<endl;
        x.time += x.period;
        pq.push(x);
    }
    return 0;
}