#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[7];
  int sum = 0;
  int lastnonzeroday = -1;
  for(int i = 0; i< 7 ; i++){
    cin>>arr[i];
    sum += arr[i];
    if(arr[i] > 0)
      lastnonzeroday = i+1;
  }

  int numbofWeeks = n/sum;
  int numbofPagesReadTillThoseWeeks = numbofWeeks * sum;
  int numbofPagesLeft = n - numbofPagesReadTillThoseWeeks;
  if(numbofPagesLeft == 0){
    cout<<lastnonzeroday;
    return 0;
  }
  int i = 0;
  while(numbofPagesLeft > 0){
    numbofPagesLeft -= arr[i];
    i = (i+1)%7;
  }
  if(i==0)
    i=7;
  cout<<i;
  return 0;
}
