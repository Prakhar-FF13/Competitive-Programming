#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];
    int numfives=0, numzeros=0;
    for(int i = 0 ; i< n ; i++){
        if(arr[i] == 5)
            numfives++;
        else
            numzeros++;
    }

    if(numzeros == 0){
        cout<<-1;
        return 0;
    }

    if(numfives < 9){
        cout<<0;
        return 0;
    }


    numfives = numfives/9;
    while(numfives--){
        cout<<555555555;
    }
    while(numzeros--){
        cout<<0;
    }
    return 0;
}
