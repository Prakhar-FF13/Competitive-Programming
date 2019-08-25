#include<bits/stdc++.h>
using namespace std;
string seq[3];
int main(){
    char c;
    seq[0]  = "qwertyuiop";
    seq[1]  = "asdfghjkl;";
    seq[2]  = "zxcvbnm,./";
    cin>>c;
    int seqlen =  seq[0].length();
    map<char, pair<int,int> > m;
    for(int i = 0 ; i < seq[0].length() ; i++){
        m[seq[0][i]]  = make_pair(0, i);
        m[seq[1][i]]  = make_pair(1, i);
        m[seq[2][i]]  = make_pair(2, i);
    }
    string str;
    cin>>str;
    int diff = (c=='R') ? -1 : 1;
    int len = str.length();
    for(int  i = 0 ;  i < len ; i++){
        pair<int,int> x = m[str[i]];
        int arrind = x.first;
        int charind = x.second;

        str[i] = seq[arrind][ (charind + diff + seqlen)%seqlen ];
    }
    cout<<str;
    return 0;
}
