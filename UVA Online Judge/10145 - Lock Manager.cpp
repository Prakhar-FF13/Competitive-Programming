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

int main () {
    RW()
    fsi
    tt() {
        unordered_set<int> blocked;
        unordered_map<int, vii> lock;
        char mode;
        int trid, item;
        while(cin>>mode) {
            if (mode == '#') {
                if(t)
                cout<<endl;
                break;
            }
            cin>>trid>>item;

            if (blocked.find(trid) != blocked.end())    cout<<"IGNORED"<<endl;
            else 
            {
                vii x = lock[item]; // all tr's which have a lock on item.
                
                if (x.size() == 0) {    // no one has a lock.
                    cout<<"GRANTED"<<endl;
                    x.pb(mp(trid, mode == 'X' ? 1 : 0));
                    lock[item] = x;
                }
                else 
                {
                    int count = x.size(); // numb of transaction with lock on item.

                    if (mode == 'X' && count > 1) { // cannot provide X lock.
                        blocked.insert(trid);
                        cout<<"DENIED"<<endl;
                    } 
                    else if (mode == 'X' && count == 1) 
                    {
                        if (x[0].first == trid) // if this transaction only has the lock.
                        { 
                            cout<<"GRANTED"<<endl;;
                            x[0].second = 1;
                            lock[item] = x;
                        } 
                        else    // some other has some other lock.
                        {    
                            cout<<"DENIED"<<endl;
                            blocked.insert(trid);
                        }
                    } 
                    else    // shared lock case.
                    {   
                        if (x[0].second == 1) // someone already has an X lock on this item.
                        {
                            if (x[0].first == trid) // this tr is the one who has X lock on this item.
                            {
                                cout<<"GRANTED"<<endl;
                            }
                            else
                            {
                                cout<<"DENIED"<<endl;
                                blocked.insert(trid);
                            }
                        }
                        else
                        {
                            int loc = -1;
                            rep(i, 0, lock[item].size())
                                if (lock[item][i].first == trid)
                                    {loc = i; break;}

                            if (loc == -1)  lock[item].pb(mp(trid, 0));

                            cout<<"GRANTED"<<endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}