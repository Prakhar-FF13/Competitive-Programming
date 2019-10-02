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

map<string, string> parent; // parent of friend s1 is s2;
map<string, int>    Rank, Size;   // rank of every root group and size of every root group.

string getSet(string name){
    if(parent.find(name) == parent.end()){
        parent[name] = name;
        Rank[name] = 0;
        Size[name] = 1;
        return name;
    }else if(parent[name] == name){
            return name;
    }else{
        return parent[name] = getSet(parent[name]);
    }
}

int getSizeOfSet(string name){
    string root = getSet(name);
    return Size[root];
}

void JoinSet(string s1, string s2){
    string p1 = getSet(s1), p2 = getSet(s2);
    if(p1 == p2)    return;
    int r1 = Rank[p1], r2 = Rank[p2];
    if(r1 < r2){
        parent[p1] = p2;
        Size[p2] += Size[p1];
    }else{
        parent[p2] = p1;
        Size[p1] += Size[p2];
        if(r1 == r2)
            r1++;
    }
}

int main(){
    //RW()
    tt(){
        parent.clear();
        Rank.clear();
        Size.clear();
        int n;
        cin>>n;
        while(n--){
            string f1,f2;
            cin>>f1>>f2;
            JoinSet(f1, f2);
            cout<<getSizeOfSet(f1)<<endl;
        }
    }
    return 0;
}
