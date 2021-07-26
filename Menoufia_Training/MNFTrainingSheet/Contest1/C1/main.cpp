#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    cin >> str;
    int tot1=0, tot2=0;
    int sz=str.length();
    for(int i=0;i<sz;i++){
        tot1 = (tot1*10 + (int)str[i] - '0')%6;
        tot2 = (tot2*10 + (int)str[i] - '0')%9;
    }
    tot1%=6;
    tot2%=9;

    if(!tot1&&!tot2){
        cout<<"6 9"<<endl;
    } else if(!tot1){
        cout<<"6"<<endl;
    } else if(!tot2){
        cout<<"9"<<endl;
    } else {
        cout<<"-1"<<endl;
    }

    return 0;
}
