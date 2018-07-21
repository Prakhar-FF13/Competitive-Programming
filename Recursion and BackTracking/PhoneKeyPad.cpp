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

string phone[10];
string ans[(int)(1e5)];
long long keypad(int n, string output[]){
	if( n == 0 || n == 1 ){
		output[0] = "";
		return 1;
	}else{
		long long subans = keypad((int)n/10, output);
		int x = n % 10;
		long long cnt = 0;
		rep(i, 0, phone[x].length()){
			rep(j, 0, subans){
				ans[cnt++] = output[j] + phone[x][i]; 
			}
		}
		rep(i, 0, cnt)
			output[i] = ans[i];
		return cnt;
	}
}

int main(){
	int n;
	cin>>n;
	phone[2]="abc"; phone[3]="def";phone[4]="ghi";phone[5]="jkl";phone[6]="mno";
	phone[7]="pqrs";phone[8]="tuv";phone[9]="wxyz";
	string output[(int)1e5];
	long long int ans = keypad(n, output);
	rep(i, 0, ans)
		cout<<output[i]<<"\n";
	return 0;
}

