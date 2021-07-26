#include <iostream>

using namespace std;

string str;
int T;
int main(){
    freopen("ocr.in", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    while(T--){
    cin >> str;
    int len=str.length();
    bool is=0;
    for(int i=0;i<len-1;i++){
        if(str[i]=='r' && str[i+1]=='n') {is=1;break;}
    }
    if(is) cout << "not sure\n";
    else cout << "sure\n";
    }
    return 0;
}
