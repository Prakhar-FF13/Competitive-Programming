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

typedef struct person {
    string name;
    int dd, mm, yyyy;
} Person;

int cmpPerson(Person p1, Person p2) {
    if (p1.yyyy == p2.yyyy) {
        if (p1.mm == p2.mm) {
            return p1.dd < p2.dd;
        }
        else    return p1.mm < p2.mm;
    }
    else    return p1.yyyy < p2.yyyy;
}

int main(){
    RW()
    int n;
    cin>>n;
    vector<Person> arr;
    rep(i, 0, n) {
        Person p;
        cin>>p.name>>p.dd>>p.mm>>p.yyyy;
        arr.pb(p);
    }
    sort(all(arr), cmpPerson);
    cout<<arr[n-1].name<<endl<<arr[0].name<<endl;
    return 0;
}
