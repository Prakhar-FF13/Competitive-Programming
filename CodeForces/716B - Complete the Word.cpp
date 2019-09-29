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

int main(){
    string s;
    cin>>s;
    if(s.length() < 26){ cout<<-1; return 0;}
    int i=0,j=0;
    int cntChar[27];
    ms(cntChar, 0, sizeof(cntChar));
    int ansI = -1, ansJ = -1;
    while(j < s.length()){
        if(j-i+1 > 26){
            if(s[i] == '?') cntChar[26]--;
            else            cntChar[s[i] - 'A']--;
            i++;
        }
        if(s[j] == '?') cntChar[26]++;
        else            cntChar[s[j] -'A']++;

        if(j - i + 1 == 26){
            int quesMarks = cntChar[26];
            int singleCharCount = 0;
            rep(k, 0, 26) singleCharCount += (cntChar[k] == 1);
            if(singleCharCount + quesMarks == 26){ ansI = i, ansJ = j; break;}
        }
        j++;
    }
    if(ansI == -1){  cout<<-1; return 0;}
    rep(i,0,ansI){
        if(s[i] != '?') cout<<s[i];
        else            cout<<"A";
    }
    rep(i, ansI, ansJ+1){
        if(s[i] != '?') cout<<s[i];
        else{
            rep(j, 0, 26)
                if(cntChar[j] == 0){ cout<<char(j+'A'); cntChar[j] = 1; break;}
        }
    }
    rep(i, ansJ+1, s.length()){
        if(s[i] != '?') cout<<s[i];
        else            cout<<"A";
    }
    return 0;
}
