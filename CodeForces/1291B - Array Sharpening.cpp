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
    tt(){
        int n;
        cin>>n;
        vector<int> arr(n); vector<bool> LR(n), RL(n);
        rep(i, 0, n)
            cin>>arr[i];
        LR[0] = RL[n-1] = true;
        if(n == 1)  cout<<"Yes"<<endl;
        else if(n == 2){
            if(arr[0] == arr[1] && arr[0] == 0)    cout<<"No"<<endl;
            else                    cout<<"Yes"<<endl;
        }else{
            bool pos = false;
            rep(i,1,n)
                LR[i] = LR[i-1] && (arr[i] >= i);
            int cnt = 1;
            for(int i = n-2; i >= 0 ; i--){
                RL[i] = RL[i+1] && (arr[i] >= cnt++);
                //cout<<i<<" "<<LR[i]<<" "<<RL[i]<<endl;
                if(RL[i] && LR[i]){
                    pos = true;
                    break;
                }
            }
            if(pos)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
