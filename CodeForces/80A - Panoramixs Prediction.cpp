#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x){
    if(x == 1)    return false;
    if(x == 2)    return true;
    for(int i = 2 ; i < x-1; i++)
        if(x % i == 0)  return false;
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    if(!isPrime(m)){
        cout<<"NO";
    }else{
        bool next_prime = true;
        for(int i = n+1; i < m ;i++)
            if(isPrime(i)) next_prime = false;
        if(next_prime)  cout<<"YES";
        else            cout<<"NO";
    }
    return 0;
}
