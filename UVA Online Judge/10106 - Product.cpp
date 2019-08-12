#include<bits/stdc++.h>
using namespace std;

string mulDigit(string str, char dig){
    string ans = "";
    int digit = dig - '0';
    int carry = 0;
    for(int i = str.length()-1 ; i >= 0 ; i--){
        int x = str[i] - '0';
        int mult = (x*digit) + carry;
        carry = mult/10;
        mult %= 10;
        ans += (mult + '0');
    }
    if(carry != 0)
        ans += carry + '0';
    reverse(ans.begin(), ans.end());
    return ans;
}

string add(string s1, string s2){
    if(s1 == "")
        return s2;
    if(s2 == "")
        return s1;
    int len1 = s1.length(), len2 = s2.length();
    int i = s1.length()-1, j = s2.length()-1;
    int carry = 0;
    string ans = "";
    reverse(ans.begin(), ans.end());
    while(i >= 0 && j >= 0){
        int x = s1[i] - '0', y = s2[j] - '0';
        x += y + carry;
        carry = x/10;
        x %= 10;
        ans += (x + '0');
        i--, j--;
    }
    while(i >= 0){
        int x = s1[i] - '0';
        x += carry;
        carry = x/10;
        x %= 10;
        ans += (x + '0');
        i--;
    }
    while(j >= 0){
        int x = s2[j] - '0';
        x += carry;
        carry = x/10;
        x %= 10;
        ans += (x + '0');
        j--;
    }
    if(carry != 0)
        ans += (carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string s1, string s2){
    string padding = "";
    string ans = "";
    for(int i = s2.length()-1; i >= 0; i--){
        string sans = mulDigit(s1, s2[i]);
        sans += padding;
        ans = add(ans, sans);
        padding += "0";
    }
    return ans;
}

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        cout<<multiply(s1, s2)<<"\n";
    }
    return 0;
}
