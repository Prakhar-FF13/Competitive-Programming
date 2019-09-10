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
    int n;
    cin>>n;
    int arr[n];
    rep(i, 0, n)
        cin>>arr[i];
    if(n == 0){ cout<<"yes\n"<<1<<" "<<1; return 0;}
    int cnt = 0;
    int i = 0;
    while( i < n-1 && arr[i] < arr[i+1] ) i++;
    if(i == n-1){    cout<<"yes\n"<<1<<" "<<1; return 0;}
    int j = n-1;
    while( j > 0 && arr[j] > arr[j-1] )   j--;
    reverse(arr+i, arr+j+1);
    int k = 0;
    while(k < n-1 && arr[k] < arr[k+1])   k++;
    if(k == n-1)    cout<<"yes\n"<<i+1<<' '<<j+1;
    else            cout<<"no";
    return 0;
}
