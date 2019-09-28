#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	string s,t;
	//cin>>s>>t;
	//automaton
	int i,j=0;
	int flag=0;
	for(i=0;i<s.length();i++){
		flag=0;
		if(t[j]==s[i]){
			j++;
			flag=1;
		}
	}
	int scount[27]={0},tcount[27]={0};
	if(j==t.length()) cout<<"automaton";
	else{
		flag=0;
		for(i=0;i<s.length();i++){
			scount[s[i]-97]++;
		}
		for(i=0;i<t.length();i++){
			tcount[t[i]-97]++;
		}
		int count=0;
		for(i=0;i<26;i++){
			flag=0;
			if(tcount[i]==scount[i]){
				flag=1;
				count++;
			}
		}
		if(count==26) cout<<"array";
		else{
                count=0;
			for(i=0;i<26;i++){
				flag=0;
				if(scount[i]>=tcount[i]){
					flag=1;
                    count++;
				}
			}
			if(count==26) cout<<"both";
			else cout<<"need tree";
		}
	}
}