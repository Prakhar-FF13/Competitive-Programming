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

unordered_map<int, pii> row,col;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int> > sheet(n, vector<int>(m, 0));
    rep(i, 1, k+1){
        int type, affected, color;
        cin>>type>>affected>>color;
        pii x = {i, color};
        if(type == 1)
            row[affected-1] = x;
        else
            col[affected-1] = x;
    }
    rep(i, 0, n){
        rep(j, 0, m){
            pii q = max(row[i], col[j]);
            if(q.first != 0)
                cout<<q.second<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
