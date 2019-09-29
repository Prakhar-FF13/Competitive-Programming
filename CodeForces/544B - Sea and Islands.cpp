#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;
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
    int n,k;
    cin>>n>>k;
    int half = n/2;
    int bigHalf = n-half;
    int maxIslandsPossible = bigHalf*bigHalf + half*half;
    if(maxIslandsPossible < k)
        cout<<"NO";
    else{
        cout<<"YES"<<endl;
        rep(i, 0, n){
            rep(j, 0, n){
                if(i%2 == 0){
                    if(j%2 == 0 && k > 0)    k--,cout<<"L";
                    else                     cout<<"S";
                }else{
                    if(j%2 == 1 && k > 0)    k--,cout<<"L";
                    else                     cout<<"S";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
