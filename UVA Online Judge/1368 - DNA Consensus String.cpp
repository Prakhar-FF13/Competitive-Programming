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

int main () {
    RW()
    fsi
    tt() {
        int n,m;
        cin>>n>>m;
        string arr[n];
        int maxOccuringChar[m][4];
        rep(i, 0, m)
            maxOccuringChar[i][0] = maxOccuringChar[i][1] = maxOccuringChar[i][2] = maxOccuringChar[i][3] = 0;

        rep(i, 0, n) {
            cin>>arr[i];
            rep(j, 0, m) {
                if (arr[i][j] == 'A')           maxOccuringChar[j][0]++;
                else if (arr[i][j] == 'C')      maxOccuringChar[j][1]++;
                else if (arr[i][j] == 'G')      maxOccuringChar[j][2]++;
                else                            maxOccuringChar[j][3]++;
            }
        }

        string ans = "";
        int diff = 0;

        rep(i, 0, m) {
            int maxCnt = max(maxOccuringChar[i][0],
                            max(maxOccuringChar[i][1],
                            max(maxOccuringChar[i][2], maxOccuringChar[i][3])));

            if (maxCnt == maxOccuringChar[i][0])         
                ans += 'A', diff += maxOccuringChar[i][1] + maxOccuringChar[i][2] + maxOccuringChar[i][3];
            else if (maxCnt == maxOccuringChar[i][1])    
                ans += 'C', diff += maxOccuringChar[i][0] + maxOccuringChar[i][2] + maxOccuringChar[i][3];
            else if (maxCnt == maxOccuringChar[i][2])    
                ans += 'G', diff += maxOccuringChar[i][0] + maxOccuringChar[i][1] + maxOccuringChar[i][3];
            else                                         
                ans += 'T', diff += maxOccuringChar[i][0] + maxOccuringChar[i][1] + maxOccuringChar[i][2];
        }

        cout<<ans<<endl<<diff<<endl;
    }
    return 0;
}