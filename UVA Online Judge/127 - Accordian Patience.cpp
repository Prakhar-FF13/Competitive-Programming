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
typedef vector<ll> vl;
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

class Card{
    private:
        char numb;
        char suite;
    public:
        Card(){ numb = '.'; suite = '.';}
        Card(string str){
            numb = str[0];
            suite = str[1];
        }
        bool operator == (Card &x){
            if(this->suite == x.suite)
                return true;
            if(this->numb == x.numb)
                return true;
            return false;
        }
        void print(){
            std::cout<<this->numb<<" "<<this->suite<<endl;
        }
};
int main(){
    RW()
    string str;
    while(cin>>str){
        if(str == "#")
            break;
        vector<list<Card> > deck;
        list<Card> x;
        x.pb(Card(str));
        deck.pb(x);
        rep(i,1,52){
            cin>>str; x.pob(); x.pb(Card(str));
            deck.pb(x);
        }
        for(int i = 0 ; i < deck.size() ; i++){
            if(i-3 >= 0 && deck[i].back() == deck[i-3].back()){
                deck[i-3].pb(deck[i].back());
                deck[i].pob();
                if(deck[i].empty())
                    deck.erase(deck.begin() + i); // remove emptied item to move everything on the right to left by 1.
                i -= 4; // return back to i-3 to check if newly added card matches previous ones.
            }else if(i-1 >= 0 && deck[i].back() == deck[i-1].back()){
                deck[i-1].pb(deck[i].back());
                deck[i].pob();
                if(deck[i].empty())
                    deck.erase(deck.begin() + i); // remove emptied item to move everything on the right to left by 1.
                i -= 2; // return back to i-3 to check if newly added card matches previous ones.
            }
        }
        printf("%d pile%s remaining:", deck.size(), deck.size() == 1 ? "" : "s");
        rep(i, 0, deck.size())
            cout<<" "<<deck[i].size();
        cout<<endl;
    }
    return 0;
}
