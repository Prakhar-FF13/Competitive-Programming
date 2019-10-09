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
vector<pair<int, pii> > cp;
vii tables;

int lowerBound(int val){
    int low = 0, high = tables.size()-1;
    while(low <= high){
        int mid = (low + high)/2;
        pii q = tables[mid];
        if(q.first >= val){
            if(high == mid)
                return mid;
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int cmp( pair<int, pii>  a, pair<int, pii> b){
    return a.second.second > b.second.second;
}

int main(){
    int n;
    cin>>n;
    rep(i,0,n){
        int c,p;
        cin>>c>>p;
        cp.pb( mp(i, mp(c, p))  );
    }
    sort(cp.begin(), cp.end(), cmp);
    int m;
    cin>>m;
    rep(i, 0, m){
        int x;
        cin>>x;
        tables.pb(mp(x, i));
    }
    sort(tables.begin(), tables.end());
    vector<pii> ans;
    int reqMade = 0, moneyMade =  0;
    rep(i, 0, n){
        pair<int, pii> x = cp[i]; // get request with highest
        int q = lowerBound(x.second.first); // find big table or equal sized table index.
        if(q == tables.size())   continue;
        else{
            moneyMade += x.second.second; // get money.
            reqMade++; // increment request made count.
            ans.pb(mp(x.first+1, tables[q].second+1));
            tables.erase(tables.begin() + q);
        }
    }
    cout<<reqMade<<" "<<moneyMade<<endl;
    //sort(ans.begin() ,ans.end());
    rep(i, 0, ans.size()){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
