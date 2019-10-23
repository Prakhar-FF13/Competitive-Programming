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

string intToBin(int a){
    string str = "";
    while(a>0){
        str += char((a%2) + '0');
        a/=2;
    }
    rep(i, str.length(), 33)
        str += '0';
    reverse(str.begin(), str.end());
    return str;
}

int binToInt(string str){
    int num = 0;
    int twoP = 1;
    for(int i = str.length()-1; i>= 0; i--){
        int x = str[i] - '0';
        num += twoP*x;
        twoP*=2;
    }
    return num;
}

string addTwoBin(string a, string b){
    string str = "";
    int carry = 0;
    int sum = 0;
    for(int i = a.length()-1 ; i >= 0; i--){
        int b1 = a[i] - '0';
        int b2 = b[i] - '0';
        sum = (((1-b2)*b1) | ((1-b1)*b2)) + carry;
        if(sum > 1){
            sum = 1;
            carry = 1;
        }else{
            carry = 0;
        }
        str += char(sum + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    int a,b;
    while(cin>>a>>b){
        cout<<binToInt(addTwoBin(intToBin(a), intToBin(b)))<<endl;
    }
    return 0;
}
