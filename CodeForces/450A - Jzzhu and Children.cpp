#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  queue<pair<int,int> > line;
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    line.push(make_pair(x, i+1));
  }
  pair<int,int> last_to_go;
  while(!line.empty()){
    pair<int,int> front = line.front();
    line.pop();
    last_to_go = front;
    if(front.first - m > 0)
      line.push(make_pair(front.first-m, front.second));
  }
  cout<<last_to_go.second;
  return 0;
}
