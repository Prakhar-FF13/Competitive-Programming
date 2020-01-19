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
#define fsi		ios_base::sync_with_stdio(false);cin.tie(0);
#define RW() 		freopen("read.txt","r",stdin);freopen("write.txt","w",stdout);
#define MOD 	1000000007
#define tt() 	int t;cin>>t;while(t--)
#define pb		push_back
#define mp		make_pair
#define ms		memset
#define all(v)		v.begin(),v.end()
#define pob		pop_back
int charCount[26*2+3];
string a,b,c;
int n;
void countChar(string str){
    rep(i ,0, 26*2+3)
        charCount[i] = 0;
    rep(i, 0, str.length()){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            int ind = str[i] - 'A';
            charCount[ind]++;
        }
        else{
            int ind = str[i] - 'a';
            charCount[ind+27]++;
        }
    }
}

int maxBeauty(string str, int t){
    int ans = 0;
    countChar(str);
    rep(i, 0, 26*2+3){
        int maxCount = charCount[i], turns = t, subAns = 0;
        if(maxCount + turns <= str.length()){
            subAns = maxCount + turns;
            turns = 0;
        }else{
            turns = turns - str.length() + maxCount;
            subAns = str.length() - (turns%2);
        }
        ans = max(ans, subAns);
    }
    return ans;
}

int main(){
    cin>>n;
    cin>>a>>b>>c;
    int bA = maxBeauty(a, n);
    int bB = maxBeauty(b, n);
    int bC = maxBeauty(c, n);
    int maxB = max(bA, max( bB, bC ));
    int countMaxB = 0;
    if(maxB == bA) countMaxB++;
    if(maxB == bB) countMaxB++;
    if(maxB == bC) countMaxB++;
    if(countMaxB >= 2)
        cout<<"Draw";
    else{
        if(maxB == bA)          cout<<"Kuro";
        else if(maxB == bB)     cout<<"Shiro";
        else                    cout<<"Katie";
    }
}
