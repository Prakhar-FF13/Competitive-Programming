/*
Nishant is a very naughty boy in Launchpad Batch.
One day he was playing with strings, and randomly shuffled them all.
Your task is to help Nishant Sort all the strings ( lexicographically )
but if a string is present completely as a prefix in another string,
then string with longer length should come first.
Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have
- Batman, bat.
*/
#include<bits/stdc++.h>
#include<string>
using namespace std;
bool cmp(string s1, string s2){
	size_t f = s2.find(s1);
	if(f != string::npos)
		return false;
	f = s1.find(s2);
	if(f != string::npos)
		return true;
	
	return s1 < s2;
}

int main() {
	int n;
	cin>>n;
	string str[n];
	for(int i = 0 ; i < n ; i++)
		cin>>str[i];
	sort(str, str + n, cmp);
	for(int i = 0 ; i < n; i++)
		cout<<str[i]<<"\n";
	return 0;
}
