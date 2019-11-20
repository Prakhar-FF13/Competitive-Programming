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

int main(){
    RW()
    int n;
    while(cin>>n){
        map<int,int> m, cnt;
        vector<int> arr;
        arr.assign(n+2, 0);
        rep(i, 0, n){
            int f,b;
            cin>>f>>b;
            m[f] = b;
            cnt[f]++;
            cnt[b]++;
        }
        /*Getting First and Last Element.. */
        int a=-1,b=-1;
        for(auto x : cnt){
            int el = x.first;
            int cn = x.second;
            if(cn == 1){
                /*First and last element only occur once in the input.*/
                if(a==-1) a = el;
                else      b = el;
            }
        }
        if(m[a] != 0){
            arr[0] = a;
            arr[n-1] = b;
        }else{
            arr[0] = b;
            arr[n-1] = a;
        }
        /* First and Last Element are now in their place */
        arr[1] = m[0]; // second element is easy just check 0 in map.
        int x = arr[1];
        /* Fill using second element */
        for(int i = 3 ; i < n ; i+=2){
            if(arr[i] != 0) break;
            arr[i] = m[x];
            x = arr[i];
        }
        /*fill using 1st element*/
        int q = 0;
        for(int i = 2; i < n ; i += 2){
            if(arr[i]!=0)   break;
            arr[i] = m[arr[q]];
            q += 2;
        }
        rep(i, 0, n)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}
