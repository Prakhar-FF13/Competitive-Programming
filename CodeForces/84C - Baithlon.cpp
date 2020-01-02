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
vector<pair<int, pii> > arr;

double Dist(int x, int r, int qx, int qy){
    double dist = sqrt(pow(x - qx, 2) + pow(qy, 2));
    return dist;
}

int firstShot[int(1e4)+5];
int main(){
    int n;
    cin>>n;
    rep(i, 0, n){
        int x,r;
        cin>>x>>r;
        arr.pb({x, {r, i}});
    }
    sort(all(arr));
    int m;
    set<int> tarHits;
    cin>>m;
    rep(i, 0, n)
        firstShot[i] = 1e9;
    rep(i, 1, m+1){
        int qx,qy;
        cin>>qx>>qy;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            int x = arr[mid].first;
            int r = arr[mid].second.first;
            int ind = arr[mid].second.second;
            if(qx < x-r)        high = mid-1;
            else if(qx > x+r)   low  = mid+1;
            else{
                double dist = Dist(x, r, qx, qy);
                if(dist < r){
                    firstShot[ind] = min(firstShot[ind], i);
                    tarHits.insert(ind);
                    break;
                }else if(dist == r){
                    firstShot[ind] = min(firstShot[ind], i);
                    tarHits.insert(ind);
                    if(qy == 0){
                        if(qx == x-r)   high = mid-1;
                        else            low  = mid+1;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
        }
    }
    cout<<tarHits.size()<<endl;
    rep(i, 0, n){
        if(firstShot[i] != 1e9)
            cout<<firstShot[i]<<" ";
        else
            cout<<-1<<" ";
    }
    return 0;
}
