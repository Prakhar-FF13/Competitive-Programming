#include<bits/stdc++.h>
using namespace std;

int main(){
	int ox,oy,x;
	for(int i = 0; i  < 5; i++){
		for(int j = 0 ; j < 5 ; j++){
			cin>>x;
			if(x==1){ ox=i+1; oy=j+1;  }
		} 
	}
	cout<<(abs(ox-3) + abs(oy-3));
	return 0;
}
