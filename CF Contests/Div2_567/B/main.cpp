#include<bits/stdc++.h>
using namespace std;

int l;
string s;
string s1, s2,s3,s4;

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        carry = sum/10;
    }

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}

void ss(){

    int num=0;
    for(int i=0;i<s1.length();i++){
        if(num == 0 || s1[i] < s1[num]) num=i;
    }

    swap(s1[0], s1[num]);

    num=0;
    for(int i=0;i<s2.length();i++){
        if(num == 0 || s2[i] < s2[num]) num=i;
    }

    swap(s1[0], s2[num]);

}


int main(){
    ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);

    cin >> l >> s;

    sort(s.begin(), s.end(), greater<int>());

    int idx=-1, zeros=count(s.begin(), s.end(), '0');
    for(int i=l-1;i>=0;i--){
        if(s[i] != '0') {idx=i; break;}
    }

    if(idx != -1) s=s.substr(0, idx+1);


    l-=zeros;

    int len=(l/2);

    bool is=false;
    if(s.length()%2==1){
        int a=len;
        while(s[a] == '0')
            a--, len++;
        s1=s.substr(a, len+1);
        s2=s.substr(0, a);
        reverse(s1.begin(), s1.end());reverse(s2.begin(), s2.end());

    } else {
        string add;
        add=s.substr(0, len-1);
        reverse(add.begin(), add.end());
        s1=s[l-1] + add;

        add=s.substr(len-1, len-1);
        reverse(add.begin(), add.end());
        s2=s[l-2] + add;
    }



    int a=0;
    while(s1.length() == s2.length()){
        if(s1[a] == s2[a]){
            a++;
            continue;
        }
        if(s1[a] > s2[a]){
            swap(s1, s2);
            break;
        } else break;
        a++;
    }


    while(zeros > 0){

        if(zeros > 0 && s1 != ""){
            s1=s1+'0';
            zeros--;
        }

        if(zeros > 0 && s2 != ""){
            s2=s2+'0';
            zeros--;
        }

    }

    sort(s1.begin()+1, s1.end());
    sort(s2.begin()+1, s2.end());

    cout << s1 << " " << s2 << endl;

    string sum=findSum(s1, s2);


    cout << sum << endl;


    return 0;
}
