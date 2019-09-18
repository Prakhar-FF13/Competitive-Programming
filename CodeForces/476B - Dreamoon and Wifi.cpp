#include<bits/stdc++.h>
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


string s1,s2;
int correctPos;
int correctPosCount;
int totalCount;
double prob;

void solve(int index, int pos){
    if(index == s2.length()){
        if(pos == correctPos)   correctPosCount++;
        totalCount++;
        return;
    }
    if(s2[index] == '+')        solve(index+1, pos+1);
    else if(s2[index] == '-')   solve(index+1, pos-1);
    else{
        solve(index+1, pos+1);
        solve(index+1, pos-1);
    }
}

int main(){
    cin>>s1>>s2;
    correctPos=0; correctPosCount=0; totalCount=0;
    rep(i, 0 , s1.length()){
        if(s1[i] == '+')    correctPos++;
        else                correctPos--;
    }
    solve(0, 0);
    printf("%.12lf", correctPosCount*1.0/totalCount*1.0);
    return 0;
}
