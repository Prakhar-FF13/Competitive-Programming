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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        if(n <= 2)  return deck;
        list<int> ind;
        for(int i = 0 ; i < n ; i ++) ind.push_back(i);
        vector<int> order;
        while(!ind.empty()){
            order.push_back(ind.front());
            ind.pop_front();
            if(!ind.empty()){
                int x = ind.front();
                ind.pop_front();
                ind.push_back(x);
            }
        }
        vector<int> ans(n);
        for(int i = 0 ;i  < n ; i++){
            ans[order[i]] = deck[i];
        }
        return ans;
    }
};


int main(){
    return 0;
}