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
string arr;

bool checkRows(char pl){
    for(int i = 0; i < 9; i+=3){
        if(arr[i] == pl && arr[i+1] == pl && arr[i+2] == pl)
            return true;
    }
    return false;
}

bool checkCols(char pl){
    for(int i = 0 ; i < 3; i++){
        if(arr[i] == pl && arr[i+3] == pl && arr[i+6] == pl)
            return true;
    }
    return false;
}

bool checkDiagnols(char pl){
    if(arr[0] == pl && arr[4] == pl && arr[8] == pl)
        return true;
    if(arr[2] == pl && arr[4] == pl && arr[6] == pl)
        return true;
    return false;
}

bool checkWins(char pl){
    return (checkRows(pl) || checkCols(pl) || checkDiagnols(pl));
}

int main(){
    while(cin>>arr){
        if(arr == "end")    break;
        bool xWins = checkWins('X');
        bool oWins = checkWins('O');
        int xCount=0, oCount=0;
        rep(i, 0, arr.length()){
            if(arr[i] == 'X')   xCount++;
            if(arr[i] == 'O')   oCount++;
        }
        if(oWins && xWins){
            cout<<"invalid\n";
        }else if(xWins){
            cout<<((xCount - oCount == 1) ? "valid\n" : "invalid\n");
        }else if(oWins){
            cout<<((xCount - oCount == 0) ? "valid\n" : "invalid\n");
        }else{
            bool valid = ((xCount-oCount == 1) && (xCount+oCount==9));
            cout<<(valid ? "valid\n":"invalid\n");
        }
    }
    return 0;
}
