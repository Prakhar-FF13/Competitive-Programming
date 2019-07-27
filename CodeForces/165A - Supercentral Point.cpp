#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int x[n];
  int y[n];
  for(int i = 0;  i< n; i++){
    cin>>x[i]>>y[i];
  }
  int ans=0;
  for(int i = 0 ; i < n ; i++){
    int cx = x[i];
    int cy = y[i];
    bool hasAbove=false, hasBelow=false, hasRight=false, hasLeft=false;
    for(int j = 0 ; j < n ; j++){
        if(i==j)
          continue;
        int dx = x[j];
        int dy = y[j];
        if(dx == cx){
          if(dy>cy)
            hasAbove=true;
          else
            hasBelow=true;
        }
        else if(dy == cy){
          if(dx > cx)
            hasRight = true;
          else
            hasLeft = true;
        }
    }
    if(hasLeft && hasAbove && hasBelow && hasRight)
      ans++;
  }
  cout<<ans;
  return 0;
}
