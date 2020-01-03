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

int main(){
    string num;
    cin>>num;
    int n = num.length();
    string s[3]; s[0] = s[1] = s[2] = "";
    bool arr[num.length()][3];
    rep(i, 0, n)
        arr[i][0] = arr[i][1] = arr[i][2] = false;
    arr[0][(num[0] - '0')%3] = true;
    s[(num[0] - '0')%3] = num[0];
    rep(i, 1, n){
        // exclude ith value
            // newRow becomes previous row in this case.
        string newS[3];
        // update newStrings if ith is ignored.
        newS[0] = s[0]; newS[1] = s[1]; newS[2] = s[2];
        // this line is important, update if it is possible to get remainders when ith value is ignored.
        arr[i][0] = arr[i-1][0], arr[i][1] = arr[i-1][1], arr[i][2] = arr[i-1][2];

        // include ith value
            // convert current number to integer and add the remainder
            // update new now.
        int numb = num[i] - '0';

        // using 0th column
        int newR = (0+numb%3)%3;
        if(newS[newR].length() < s[0].length() + 1 && arr[i-1][0])
            newS[newR] = s[0] + num[i], arr[i][newR] = true;

        // using 1th column
        newR = (1+numb%3)%3;
        if(newS[newR].length() < s[1].length() + 1 && arr[i-1][1])
            newS[newR] = s[1] + num[i], arr[i][newR] = true;

        // using 2th column
        newR = (2+numb%3)%3;
        if(newS[newR].length() < s[2].length() + 1 && arr[i-1][2])
            newS[newR] = s[2] + num[i], arr[i][newR] = true;


        // handle the case when the starting with ith number.
        newR = numb%3;
        if(newS[newR].length() < 1)
            newS[newR] = num[i], arr[i][newR] = true;

        s[0] = newS[0]; s[1] = newS[1]; s[2] = newS[2];
        //cout<<s[0]<<"   "<<s[1]<<"   "<<s[2]<<endl;
    }
    if(s[0].length() == 0)
        cout<<-1;
    else{
        int ind = 0;
        while(s[0][ind] == '0') ind++;
        if(ind == s[0].length()) cout<<0;
        else
            rep(i, ind, s[0].length())
                cout<<s[0][i];
    }
    return 0;
}
