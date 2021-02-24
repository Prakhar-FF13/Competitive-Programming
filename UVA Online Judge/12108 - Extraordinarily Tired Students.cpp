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
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<double, pii> pdii;
typedef pair<double, pll> pdll;
typedef vector<pdii> vdii;
typedef vector<pdll> vdll;
#define rep(i,a,b)		for(int i=a;i<b;i++)
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

typedef struct student {
    int a,b,c;
} S;

int main () {
    RW()
    fsi
    int cp = 1, n;
    while(cin>>n) {
        if (n == 0) break;
        S arr[n];
        queue<char> q[n];
        rep(i, 0, n) {
            cin>>arr[i].a>>arr[i].b>>arr[i].c;
            if (arr[i].c <= arr[i].a)  {
                int x = arr[i].a - arr[i].c + 1; // Awake for how many minutes.
                while(x--)  q[i].push('A');     // store in queue the count.
            }
            else {
                int x = arr[i].a + arr[i].b - arr[i].c + 1; // will sleep for how many minutes.
                while(x--)  q[i].push('S');     // store in q the count.
            }
        }
        bool possible = false;
        int tim = 1, iter = 300;
        while(iter--) {
            // all awake at this moment.
            int awakeCount = 0;
            rep(i, 0, n) awakeCount += q[i].front() == 'A';

            if (awakeCount == n) { // all awake answer found.
                possible = true;
                break;
            };

            // stay awake or sleep for 1 minute if already in one of these states.
            rep(i, 0, n) {
                // if last sleeping minute then after this he will be awake for at-least a minutes.
                if (q[i].size() == 1 && q[i].front() == 'S') {
                    int x = arr[i].a;
                    while(x--)  q[i].push('A');  // store next state as awake after this minute passes.
                }
                if (q[i].size())    q[i].pop(); // minute passed so remove one state.
            }

            // get nextState for ppl who have completed their awake (stayed awake for 'a' minutes)
            // if more than half are asleep put to sleep others who want to sleep.
            char sora = (n - awakeCount) > awakeCount ? 'S' : 'A';
            rep(i, 0 ,n)
                if (q[i].size() == 0) {
                    int p;
                    if (sora == 'S')    p = arr[i].b;
                    else                p = arr[i].a;
                    while(p--)          q[i].push(sora);
                }

            tim++;
        }
        cout<<"Case "<<cp++<<": ";
        if (possible)
            cout<<tim<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}