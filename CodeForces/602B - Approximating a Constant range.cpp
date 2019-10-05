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

unordered_map<int,int> last_index;

int main(){
    //RW()
    int n;
    cin>>n;
    vector<int> arr(n);
    rep(i,0,n)
        cin>>arr[i];
    int min_index = 0, max_index = 0;
    int i=0,j=0;
    int window=0;
    while(j < n){
        bool maxMin;
        last_index[arr[j]] = j;
        if(arr[j] >= arr[max_index]){
            max_index = j;
            maxMin = true;
        }
        if(arr[j] <= arr[min_index]){
            min_index = j;
            maxMin = false;
        }
        int diff = arr[max_index] - arr[min_index];
        if(diff >= 2){
            if(maxMin){
                // last position of next min element.
                min_index = last_index[arr[min_index]]+1;
                i=min_index;
            }else{
                // last position of next max element.
                max_index = last_index[arr[max_index]]+1;
                i=max_index;
            }
        }
        if(window < j-i+1){
            window = j-i+1;
        }
        j++;
    }
    std::cout<<window;
    return 0;
}
