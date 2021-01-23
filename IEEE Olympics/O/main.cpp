#include <iostream>

using namespace std;
int T;
string str;
int main(){
    cin >> T;
    while(T--){
        cin >> str;
        int len=str.length();
        if(str[0]=='0' || len != 10){
            printf("NO\n");
            continue;
        }
        bool is=1;
        for(int i=0;i<len;i++){
            if(str[i]-'0' >=0 && str[i]-'0' <=9) continue;
            else {
                is=0;break;
            }
        }
        if(!is) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
