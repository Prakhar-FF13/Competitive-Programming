#include<iostream>
#include<cstdio>
#include<string.h>
#include<climits>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<algorithm>

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
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        vector<int> ans(2);
        vector<pair<int,int> > arr(j+1);
        for(int i = 0; i < j+1; i++)
            arr[i] = make_pair(nums[i], i);
        sort(arr.begin(), arr.end());
        while(i<j){
            if(arr[i].first+arr[j].first == target){
                ans[0] = arr[i].second, ans[1] = arr[j].second;
                break;
            }
            else if(arr[i].first + arr[j].first < target) i++;
            else                              j--;
        }
        return ans;
    }
};

int main(){
    return 0;
}
