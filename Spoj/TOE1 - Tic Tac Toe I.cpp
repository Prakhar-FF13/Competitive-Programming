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
bool wins(vector<string> tic, char pl){
    rep(i, 0 ,3){
        if(tic[i][0] == pl && tic[i][1] == pl && tic[i][2] == pl)   return true;
        if(tic[0][i] == pl && tic[1][i] == pl && tic[2][i] == pl)   return true;
    }
    if(tic[0][0] == pl && tic[1][1] == pl && tic[2][2] == pl)       return true;
    if(tic[0][2] == pl && tic[1][1] == pl && tic[2][0] == pl)       return true;

    return false;
}
map<vector<string>, int > posibs;
void build(vector<string> tic, int chance, int total){
    bool xwins = wins(tic, 'X');
    bool owins = wins(tic, 'O');
    posibs[tic] = 1;
    if(xwins || owins || total == 9)    return;
    rep(i, 0, 3)
        rep(j, 0, 3)
            if(tic[i][j] == '.'){
                tic[i][j] = (chance == 0) ? 'X' : 'O';
                build(tic, 1-chance, total+1);
                tic[i][j] = '.';
            }
}


int main(){
    RW()
    vector<string> arr;
    arr.pb("..."); arr.pb("..."); arr.pb("...");
    build(arr, 0, 0);
    /*for(auto it = posibs.begin(); it!=posibs.end(); it++){
        arr = *it;
        cout<<arr[0]<<"\n"<<arr[1]<<"\n"<<arr[2]<<endl<<endl;
    }
    cout<<posibs.size()<<endl;*/
    //cout<<posibs.size()<<"\n";
    tt(){
        arr.clear();
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        arr.pb(s1); arr.pb(s2); arr.pb(s3);
        if(posibs[arr])
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
