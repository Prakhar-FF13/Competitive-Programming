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

int dotOrNot[int(3e5+7)];


int main(){
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    int segments = 0;
    int total = 0;
    rep(i, 0, str.length()){
        if(str[i] == '.'){
            if(i == 0 || str[i-1] != '.')
                segments++;
            total++;
            dotOrNot[i+1] = 1;
        }else
            dotOrNot[i+1] = 0;
    }
    while(m--){
        int x;
        char c;
        scanf("%d %c", &x, &c);
        bool isDot = (c == '.');
        bool sXDot = (dotOrNot[x] == 1);
        if(isDot != sXDot){
            if(isDot)   total++;
            else        total--;

            if(dotOrNot[x-1] && dotOrNot[x+1] && sXDot)
                segments++;
            if(dotOrNot[x-1] && dotOrNot[x+1] && !sXDot)
                segments--;
            if(!dotOrNot[x-1] && !dotOrNot[x+1] && sXDot)
                segments--;
            if(!dotOrNot[x-1] && !dotOrNot[x+1] && !sXDot)
                segments++;
        }
        dotOrNot[x] = isDot;
        cout<<total - segments<<endl;
    }

    return 0;
}
