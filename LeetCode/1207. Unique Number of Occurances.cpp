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

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int numbCount[2005];
        memset(numbCount, 0, sizeof(numbCount));
        set<int> Uniquenums;
        for(int i = 0; i < arr.size() ; i++){
            numbCount[arr[i] + 1000]++;
            Uniquenums.insert(arr[i]);
        }
        set<int> Uniquecount;
        for(int i = 0 ; i < 2002 ; i++)
            if(numbCount[i] != 0)
                Uniquecount.insert(numbCount[i]);
        return (Uniquecount.size() == Uniquenums.size());
    }
};

int main(){
    return 0;
}


