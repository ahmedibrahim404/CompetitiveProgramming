#include <iostream>

using namespace std;
string ans="",str;
int main(){
    cin >> str;
    ans=str[0];
    int idx=1,to=str.length();
    for(int i=0;i<to-1;i++){
        cin >> str;
        ans += str[idx++];
    }
    cout << ans << endl;
    return 0;
}
