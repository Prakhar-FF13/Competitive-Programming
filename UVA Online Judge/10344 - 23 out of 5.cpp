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
int arr[5];
bool possible;
void solve(int i, int num){
    if(i == 5){
        if(num == 23)
            possible = true;
        return;
    }
    solve(i+1, num + arr[i]);
    solve(i+1, num - arr[i]);
    solve(i+1, num * arr[i]);
}

void generatePermutation(int index){
    if(index == 5){
        solve(1, arr[0]);
        return;
    }
    rep(i, index, 5){
        swap(arr[i], arr[index]);
        generatePermutation(index+1);
        swap(arr[i], arr[index]);
    }
}

int main(){
    RW()
    while(cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]){
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0)
            break;
        possible = false;
        generatePermutation(0);
        if(possible)    cout<<"Possible";
        else            cout<<"Impossible";
        cout<<endl;
    }
    return 0;
}
