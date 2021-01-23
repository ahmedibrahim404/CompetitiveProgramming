#include <iostream>

using namespace std;
int t;
string str;
int main(){
    cin >> t;
    while(t--){
        cin >> str;
        int len=str.length(), ans=0;
    int op1=0, op2=0;

        for(int i=0;i<len;i++){

            if(str[i]=='(') op1++;
            else if(str[i]=='[') op2++;
            else if(str[i]==')'){
                if(op1) op1--, ans++;
            } else if(str[i]==']'){
                if(op2) op2--, ans++;
            }

        }
        cout << ans << "\n";
    }
    return 0;
}
