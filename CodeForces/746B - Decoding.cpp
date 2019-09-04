#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    char arr[n];
    if(n == 1 || n == 2)
        cout<<str;
    else{
        int i = 0, x = n/2;
        if(!(n&1))
            x -= 1;
        arr[x] = str[i++];
        int left = x - 1;
        int right = x + 1;
        while(i < n){
            if((n-i)%2 == 1){
                if(right < n) arr[right++] = str[i++];
                else arr[left--] = str[i++];
            }
            else{
                if(left >= 0) arr[left--] = str[i++];
                else arr[right++] = str[i++];
            }
        }
        for(int i = 0 ; i < n ;  i++)
            cout<<arr[i];
    }

    return 0;
}
