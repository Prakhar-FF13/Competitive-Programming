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

int main(){
    int n,m;
    cin>>n>>m;
    vector< vector<int> > B(n, vector<int>(m)), A(n, vector<int>(m));
    vector<int> cols(m, 0), rows(n, 0);
    int zero_count=0;
    rep(i,0,n)
        rep(j,0,m){
            cin>>B[i][j];
            if(B[i][j] == 1){
                cols[j]++;
                rows[i]++;
            }else{
                zero_count++;
            }
        }
    if(zero_count == n*m){
        cout<<"YES\n";
        rep(i, 0, n){
            rep(j, 0, m){
                cout<<0<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
    rep(i, 0, n)
        rep(j, 0, m)
            if(B[i][j] == 1){
                if(rows[i] == m)    continue;
                if(cols[j] == n)    continue;
                cout<<"NO";
                return 0;
            }
    int one_count=0;
    rep(i, 0, n)
        rep(j, 0, m){
            if(rows[i] == m && cols[j] == n){
                one_count++;
                A[i][j] = 1;
            }else{
                A[i][j] = 0;
            }
        }
    if(one_count == 0)
        cout<<"NO";
    else{
        cout<<"YES\n";
        rep(i,0,n){
            rep(j,0,m)
                cout<<A[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
