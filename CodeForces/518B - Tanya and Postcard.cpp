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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    //freopen("in.txt","r",stdin);

    ll i,j,k;
    string s,t;
    map<char,ll> np;

    cin>>s>>t;

    for(i=0;i<t.length();i++)
        np[t[i]]++;

    ll c1=0,c2=0;

    //yay count
    for(i=0;i<s.length();i++)
    {
        if(np[s[i]]>0)
        {
            c1++;np[s[i]]--;s[i]='-';
        }
    }

    //whoops count
    for(i=0;i<s.length();i++)
    {
        if(s[i]!='-')
        {
            if(islower(s[i]) && np[toupper(s[i])]>0)
                np[toupper(s[i])]--,c2++;
            else if(isupper(s[i]) && np[tolower(s[i])]>0)
                np[tolower(s[i])]--,c2++;
        }
    }

    cout<<c1<<" "<<c2;

    cin.clear();
    cin.ignore();
    cin.get();

    return 0;
}