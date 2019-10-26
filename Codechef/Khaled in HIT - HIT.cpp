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

bool check(vector<int> &arr, int st, int et){
    rep(i, st, et)
        if(arr[i] >= arr[et])
            return false;
    return true;
}

int main(){
    RW()
    tt(){
        int n;
        cin>>n;
        vector<int> arr(n);
        rep(i, 0, n){
            cin>>arr[i];
        }
        sort(all(arr));
        int x = n/4;
        int y = n/2;
        int z = (3*n)/4;
        if(!check(arr, 0, x)){
            cout<<-1<<endl; continue;
        }
        if(!check(arr, x, y)){
            cout<<-1<<endl; continue;
        }
        if(!check(arr, y, z)){
            cout<<-1<<endl; continue;
        }
        rep(i, z, n)
            if(arr[i] < arr[z]){
                cout<<-1<<endl; continue;
            }
        cout<<arr[x]<<" "<<arr[y]<<" "<<arr[z]<<endl;

    }
    return 0;
}
