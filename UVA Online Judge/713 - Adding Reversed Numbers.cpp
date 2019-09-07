#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int i =0, j =0;
        int len1 = s1.length(), len2 = s2.length();
        string ans="";
        int carry = 0;
        while(i < len1 && j < len2){
            int num1 = s1[i]-'0';
            int num2 = s2[j]-'0';
            num1 += num2 + carry;
            carry = num1/10;
            num1 = num1%10;
            ans += to_string(num1);
            i++,j++;
        }
        while(i < len1){
            int x = s1[i] - '0';
            x += carry;
            carry = x/10;
            x = x%10;
            ans += to_string(x);
            i++;
        }
        while(j < len2){
            int x = s2[j] - '0';
            x += carry;
            carry = x/10;
            x = x%10;
            ans += to_string(x);
            j++;
        }
        if(carry)
            ans += to_string(carry);
        ans.erase(0, ans.find_first_not_of('0'));
        cout<<ans<<endl;
    }
    return 0;
}
