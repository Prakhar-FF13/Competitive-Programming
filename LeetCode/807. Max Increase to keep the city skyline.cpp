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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        /* Uncomment.
        int rows = grid.size();
        int cols = grid[0].size();
        int row_max[rows], col_max[cols];
        for(int i = 0; i  < rows; i++){
            row_max[i] = -1;
            for(int j = 0 ; j < cols ; j++)
                row_max[i] = max(row_max[i], grid[i][j]);
        }
        for(int i = 0; i < cols; i++){
            col_max[i] = -1;
            for(int j = 0 ; j < rows ; j++)
                col_max[i] = max(col_max[i], grid[j][i]);
        }
        int sum = 0;
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j < cols; j++){
                sum += min(row_max[i], col_max[j]) - grid[i][j];
            }
        }
        return sum;*/
    }
};

int main(){
    return 0;
}
