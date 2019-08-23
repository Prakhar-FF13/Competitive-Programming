#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a,d;
ll gcd(ll a,ll b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

void inclusion_exclusion(ll q[], ll taken, ll index, ll &ans, string str){
    if(index == 5){
        if(taken == 0)  return;
        ll gc = -1, cnt=0, lcm=1;
        for(int i = 0 ; i  < 5 ; i++){
            if(taken & (1<<i)){
                cnt++;
                if(gc == -1)
                    gc = q[i], lcm = q[i];
                else{
                    gc = gcd(lcm, q[i]);
                    lcm *= q[i];
                    lcm /= gc;
                }
            }
        }
        if(cnt%2!=0)
            ans += m/lcm - (n-1)/lcm;
        else
            ans -= m/lcm - (n-1)/lcm;
        return;
    }
    inclusion_exclusion(q, taken | (1<<index), index+1, ans, str + " " + to_string(q[index]));
    inclusion_exclusion(q, taken, index+1, ans, str);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>a>>d;
        ll nums[5] = {0};
        ll total = 0;
        for(int i = 0 ; i < 5 ; i++){
            nums[i] = a + i*d;
        }
        ll ans=0;
        inclusion_exclusion(nums, 0, 0, ans, "");
        cout<<(m-n+1)-ans<<"\n";
    }
    return 0;
}
