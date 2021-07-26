#include<bits/stdc++.h>

using namespace std;
typedef pair<int ,int>pi;
int n;
string str, strs[2*100+2];
int ans[2*100+2];
map<string, int> mp;
int main(){
    cin >> n;
    string str1, str2;
    bool is2=0;
    for(int i=0;i<2*n-2;i++){
        cin >> strs[i];
        str=strs[i];
        int len=str.length();
        if(mp.find(str)!=mp.end())
        mp[str+"_"]=i;
        else mp[str]=i;
        if(len==n-1){
            if(is2){str2=str;continue;}
            str1=str, is2=1;
        }
    }
    bool is=1;
    for(int i=1;i<=n-1;i++){
        string st1=str2.substr(n-1-i, i);
        string st2=str1.substr(0, i);
        if(mp.find(st1)!=mp.end() && mp.find(st2) != mp.end() && st1 != st2) continue;
        if(st1==st2){
            if(mp.find(st1+"_")==mp.end()){is=0;break;}
            else continue;
        }
        is=0;
    }
    if(is){
    for(int i=1;i<=n-1;i++){
        ans[mp[ str1.substr(0, i) ]]=1;
    }
    } else {
    for(int i=1;i<=n-1;i++){
        ans[mp[ str2.substr(0, i) ]]=1;
    }
    }


    for(int i=0;i<2*n-2;i++){
        if(ans[i]) cout << "P";
        else cout << "S";
    }




    return 0;
}
