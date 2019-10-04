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

vector<pair<int, string> > Nodes;

pair<int, string> parseInput(string str){
    int numb = 0;
    string path = "";
    for(int i = 0; i < str.length() ; i++){
        if(str[i] == 'L' || str[i] == 'R')
            path += str[i];
        else if(str[i] >= '0' && str[i] <= '9'){
            numb *= 10;
            numb += int(str[i] - '0');
        }
    }
    return mp(numb, path);
}
int cmp(pair<int,string> a, pair<int, string> b){
    return a.second.length() < b.second.length();
}

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x){ val = x; left = NULL; right = NULL; }
}*root = NULL;

bool insert(int val, string path, int index){
    if(root == NULL && path.length() == index){
        root = new TreeNode(val);
        return true;
    }else if(root == NULL && path.length() != index){
        return false;
    }else if(root != NULL && path.length() == 0){
        return false;
    }else{
        TreeNode *temp = root;
        while(index < path.length()-1){
            if(temp == NULL)
                return false;
            if(path[index] == 'L')
                temp = temp->left;
            else
                temp = temp->right;
            index++;
        }
        TreeNode *nd = new TreeNode(val);
        if(path[index] == 'L' && temp!= NULL && temp->left == NULL){
            temp->left = nd;
            return true;
        }else if(path[index] == 'R' && temp!= NULL && temp->right == NULL){
            temp->right = nd;
            return true;
        }
        return false;
    }
}

void levelOrder(){
    queue<TreeNode*> q;
    vector<int> vals;
    TreeNode *x = root;
    q.push(x);
    while(!q.empty()){
        TreeNode *ft = q.front();
        vals.push_back(ft->val);
        q.pop();
        if(ft->left != NULL)
            q.push( ft->left );
        if(ft->right != NULL)
            q.push( ft->right );
    }
    int len = vals.size();
    rep(i, 0, len){
        cout<<vals[i];
        if(i != len-1)
            cout<<" ";
    }
}


void process(){
    sort(Nodes.begin(), Nodes.end(), cmp);
    /*rep(i, 0, Nodes.size()){
        cout<<Nodes[i].first<<" "<<Nodes[i].second<<endl;
    }*/
    bool complete = true;
    root = NULL;
    rep(i, 0, Nodes.size()){
        int val = Nodes[i].first;
        string path = Nodes[i].second;
        if(!insert(val, path, 0)){
            complete = false;
            break;
        }
    }
    if(!complete)
        cout<<"not complete"<<endl;
    else{
        levelOrder();
        cout<<endl;
    }
    Nodes.clear();
}

int main(){
    //RW()
    string str;
    while(cin>>str){
        if(str == "()"){
            process();
        }else if(str[1] == ','){
            cout<<"not complete"<<endl;
        }
        else{
            Nodes.pb(parseInput(str));
        }
    }
    return 0;
}
