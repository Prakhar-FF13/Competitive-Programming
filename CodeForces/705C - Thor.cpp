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
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back
int n,q,total;
int unreadappNotification[300010];
int TimeLine[300010];
int lastRead[300010]; // ith application was read upto [i]th time.
int timeLine, query3Start;
int main(){
    //RW()
    cin>>n>>q;
    total = 0;
    timeLine = query3Start = 1;
    rep(i, 0, 300010){
        TimeLine[i] = 0; // at time t app[t] generated a notification.
        unreadappNotification[i] = 0; // app x has [x] unread notifications.
        lastRead[i] = -1; // all message of app x were read till point [x].
    }
    while(q--){
        int type, x;
        cin>>type>>x;
        if(type==1){
            // application x generates a notification.
            unreadappNotification[x]++; // app generated a new notification not read.
            TimeLine[timeLine++] = x; // at time t notification generated was by app x;
            total += 1;
        }else if(type==2){
            // application x read upto this point.
            total -= unreadappNotification[x]; // all notifications read of app x
            unreadappNotification[x] = 0; // make 0 as all read.
            lastRead[x] = timeLine-1; // all notification read upto point time t-1;
        }else{
            for(; query3Start <= x ; query3Start++){ // start from query till x
                int app = TimeLine[query3Start]; // get app at time t.
                //cout<<app<<"   "<<lastRead[app]<<endl;
                if(lastRead[app] >= query3Start) // if all notifications upto query were read then ignore.
                    continue;
                lastRead[app] = query3Start;
                total--;
                unreadappNotification[app]--;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}
