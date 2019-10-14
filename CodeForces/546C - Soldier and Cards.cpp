#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
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

int main(){
    int n;
    set<pair<list<int> , list<int>> > s;
    list<int> a, b;
    cin>>n;
    int k1,k2;
    cin>>k1;
    rep(i, 0, k1){
        int c;
        cin>>c;
        a.push_back(c);
    }
    cin>>k2;
    rep(i, 0, k2){
        int c;
        cin>>c;
        b.push_back(c);
    }
    int fight = 0;
    while(1){
        if(s.find(mp(a,b)) != s.end()){
            cout<<-1;
            break;
        }
        s.insert(mp(a,b));
        if(a.size() == 0){
            cout<<fight<<" "<<2;
            break;
        }else if(b.size() == 0){
            cout<<fight<<" "<<1;
            break;
        }else{
            int x = a.front();
            int y = b.front();
            //cout<<x<<" "<<y<<endl;
            a.pop_front(); b.pop_front();
            if(x > y){
                a.push_back(y);
                a.push_back(x);
            }else{
                b.push_back(x);
                b.push_back(y);
            }
            fight++;
        }
    }
    return 0;
}


