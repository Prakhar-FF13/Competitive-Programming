#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int cnt = 0;
  for(int i = 0 ; i < n ; i++){
    int x;
    cin>>x;
    cnt += x;
  }
  int ans = 0;
  n++;
  cnt--;
  for(int i = 1; i <= 5 ; i++){
    int total = cnt + i;
    if(total % n != 0){
      ans++;
    }
  }
  cout<<ans;

  return 0;
}
