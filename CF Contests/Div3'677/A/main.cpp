#include <iostream>

using namespace std;
int t;
string str;
int main(){
    int n;
    cin >> n >> str;
    int tot=0;
    for(int i=0;i<n;i+=2){
        if(str[i]==str[i+1]){
                tot++;
            if(str[i+1]=='a') str[i+1]='b';
            else str[i+1]='a';
        }
    }
    cout << tot << "\n" << str << "\n";
    return 0;
}
