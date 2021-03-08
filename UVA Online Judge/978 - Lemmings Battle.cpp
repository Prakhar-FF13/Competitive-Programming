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

int main () {
    RW()
    fsi
    tt() {
        int b,sg,sb;
        cin>>b>>sg>>sb;
        priority_queue<int, vector<int>, less<int> > arr1, arr2;
        rep(i, 0, sg)   {int x; cin>>x; arr1.push(x);}
        rep(i, 0, sb)   {int x; cin>>x; arr2.push(x);}

        while(arr1.size() && arr2.size()) {
            vector<int> a,c;
            int count = min(b, int(min(arr2.size(),arr1.size())));
            rep(i, 0, count){
                if (arr1.top() > arr2.top())            {a.pb(arr1.top()-arr2.top());}
                else if (arr2.top() > arr1.top())       {c.pb(arr2.top()-arr1.top());}
                arr1.pop(); arr2.pop();
            }
            rep(i, 0, a.size()) arr1.push(a[i]);
            rep(i, 0, c.size()) arr2.push(c[i]);
        }

        if (!arr1.size() && !arr2.size())
            cout<<"green and blue died"<<endl;
        else if (arr1.size()) {
            cout<<"green wins"<<endl;
            while(arr1.size()) {
                cout<<arr1.top()<<endl;
                arr1.pop();
            }
        } else {
            cout<<"blue wins"<<endl;
            while(arr2.size()) {
                cout<<arr2.top()<<endl;
                arr2.pop();
            }
        }
        if (t)
            cout<<endl;
    }
    return 0;
}