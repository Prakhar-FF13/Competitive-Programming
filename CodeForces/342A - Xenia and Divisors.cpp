#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[8];
    for(int i = 0 ; i < 8 ; i++)
        arr[i] = 0;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin>>x;
        arr[x]++;
    }
    if((arr[1] == 0) || (arr[2] == 0 && arr[3] == 0))
        cout<<-1;
    else{
        // 1 2 4 tripled
        int a = min(arr[1], min(arr[2], arr[4]));
        if(a!=0)
            arr[1] -= a ; arr[2] -= a ; arr[4] -= a;

        // 1 2 6 triplet
        int b = min(arr[1], min(arr[2], arr[6]));
        if(b!=0)
            arr[1] -= b ; arr[2] -= b ; arr[6] -= b;

        // 1 3 6 triplet
        int c = min(arr[1], min(arr[3], arr[6]));
        if(c!=0)
            arr[1] -= c ; arr[3] -= c ; arr[6] -= c;

        if((a + b + c) != int(n/3))
            cout<<-1;
        else{
            while(a != 0){ cout<<1<<" "<<2<<" "<<4<<"\n"; a--; }
            while(b != 0){ cout<<1<<" "<<2<<" "<<6<<"\n"; b--; }
            while(c != 0){ cout<<1<<" "<<3<<" "<<6<<"\n"; c--; }
        }
    }
    return 0;
}
