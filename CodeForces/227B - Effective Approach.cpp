#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long cmp_front = 0, cmp_back = 0;
  int arr[n+1];
  for(int i = 1 ; i <= n ; i++){
    int x;
    cin>>x;
    arr[x] = i;
  }
  int m;
  cin>>m;
  while(m--){
    int x;
    cin>>x;
    int index = arr[x];
    cmp_front += (index - 1 + 1);
    cmp_back += (n - index + 1);
  }
  cout<<cmp_front<<" "<<cmp_back;
  return 0;
}
