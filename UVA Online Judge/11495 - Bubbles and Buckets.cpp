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
#define rrep(i,a,b)   for(int i=a;i>b;i--)
#define fsi		        ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		    freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	        1000000007
#define tt() 	        int t;cin>>t;while(t--)
#define pb		        push_back
#define mp		        make_pair
#define mt              make_tuple
#define ms		        memset
#define get(t,ind)      get<ind>(t)
#define all(v)	        v.begin(),v.end()
#define pob		        pop_back

ll invCount;

void merge(int arr[], int low, int mid, int high) {
    int l1 = mid - low + 1, l2 = high - mid;
    int lowMid[l1], midHigh[l2];
    // copy sorted arrays.
    rep(i, low, mid+1)          lowMid[i-low] = arr[i]; 
    rep(i, mid+1, high+1)       midHigh[i-mid-1] = arr[i];

    //Merge arrays.
    int i = 0, j = 0, k = low;
    while (i < l1 && j < l2) {
        if (lowMid[i] <= midHigh[j]) {
            arr[k++] = lowMid[i++];
        } else {
            invCount += (ll(mid) - ll(i + low) + 1LL);
            arr[k++] = midHigh[j++];
        }
    }
    // fill remaining values.
    while(i < l1)   arr[k++] = lowMid[i++];
    while(j < l2)   arr[k++] = midHigh[j++];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    RW()
    int n;
    while(cin>>n) {
        if (n == 0) break;
        invCount = 0;
        int arr[n];
        rep(i, 0, n)    cin>>arr[i];
        mergeSort(arr, 0, n-1);
        cout<<((invCount%2 == 1) ? "Marcelo" : "Carlos");
        cout<<endl;
    }
    return 0;
}
