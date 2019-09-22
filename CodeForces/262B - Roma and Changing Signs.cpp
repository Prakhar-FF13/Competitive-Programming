#include<bits/stdc++.h>
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
    int arr[n];
    rep(i, 0, n)
        cin>>arr[i];
    int i = 0;
    while(i < n && k > 0 && arr[i] < 0){
        arr[i] = -arr[i];
        i++;
        k--;
    }
    sort(arr, arr+n);
    if(k > 0){
        k = k%2;
        if(k & 1)
            arr[0] = -arr[0];
    }
    ll sum = 0 ;
    rep(i, 0, n)
        sum += arr[i];
    cout<<sum;
    return 0;
}
