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

typedef struct medicine {
    int id, time, period;
    string name;

    medicine(int a, int b, string str) {
        id = a;
        time = b;
        period = b;
        name = str;
    }
} M;

struct cmp {
    bool operator()(M const& a, M const& b) {
        if (a.time == b.time)   return a.id > b.id;
        else                    return a.time > b.time;
    }
};

int main () {
    RW()
    fsi
    tt() {
        int n,k;
        cin>>n>>k;
        priority_queue<M, vector<M>, cmp> pq;
        rep(i, 0, n) {
            string str; int a;
            cin>>str>>a;
            pq.push(*(new M(i, a, str)));
        }
        while(k--) {
            M x = pq.top();
            pq.pop();
            cout<<x.time<<" "<<x.name<<endl;
            x.time += x.period;
            pq.push(x);
        }
    }
    return 0;
}