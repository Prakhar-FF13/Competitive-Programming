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

int main(){
	map<char, int> m;
	m['('] = 0;m['+'] = 1;m['-'] = 2;m['*'] = 3;m['/'] = 3;m['^'] = 4; 
	tt(){
		string str;
		cin>>str;
		stack<int> s;
		string rps = "";
		while(!s.empty())
			s.pop();
		rep(i,0,str.length()){
			char c = str[i];
			if(c >= 'a' && c <= 'z')
				rps += c;
			else if( c == '(')
				s.push(c);
			else if( c == ')'){
				while(!s.empty()){
					if(s.top() == '('){
						s.pop();
						break;
					}
					else{
						rps += s.top();
						s.pop();
					}
				}
			}
			else{
				while(!s.empty()){
					if(m[s.top()] >= m[c]){
						rps += s.top();
						s.pop();
					}
					else{
						break;
					}
				}
				s.push(c);
			}
		}
		cout<<rps<<"\n";
	}
	return 0;
}
