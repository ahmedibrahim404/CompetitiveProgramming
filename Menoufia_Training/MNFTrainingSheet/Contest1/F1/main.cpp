#include <iostream>

using namespace std;
string str;
int main(){
    cin>>str;
    int len=str.length(), tot=0;
    for(int i=0;i<len-1;i++){
        if(str[i]==':'&&str[i+1]==')') tot++, i++;
    }
    int cur=tot, mx=tot, temp=0;
    for(int i=0;i<len;i++){
        temp=0;
        if(str[i]==':'&&str[i+1]==')') cur--;
        if(str[i]==':'&&str[i-1]=='(') cur++;
        if(str[0]==':'&&str[i+1]==')') temp++;
        if(cur+temp>mx){
//            cout<<i<<endl;
            mx=cur+temp;
        }
    }
    cout << mx << endl;
    return 0;
}
