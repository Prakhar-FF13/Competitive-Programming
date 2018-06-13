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

int getM(char ch)
{
	switch(ch)
	{
	case 'H': return 1;
	case 'O': return 16;
	case 'C': return 12;
	}
	return 0;
}
int main(){
	char str[150];
	int i, v;
	stack < int > S;
	scanf("%s", str);
	for(i=0; str[i]; i++)
	{
		if(isdigit(str[i]))
		{
			v = S.top();
			S.pop();
			S.push(v * (str[i]-'0'));
		}
		else if(str[i]=='(') S.push(-1);
		else if(str[i]==')')
		{
			v = 0;
			while(!S.empty() && S.top()!=-1)
			{
				v += S.top();
				S.pop();
			}
			S.pop();
			S.push(v);
		}
		else if(isalpha(str[i])) S.push(getM(str[i]));
	}
	v = 0;
	while(!S.empty())
	{
		v += S.top();
		S.pop();
	}
	printf("%d\n", v);
	return 0;
}
