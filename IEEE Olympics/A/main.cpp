#include <iostream>

using namespace std;
string n;
int m;
int main(){
    cin >> n >> m;
    int len=n.length();
    for(int i=0;i<len&&m;i++){
        if(n[i]!='9') n[i]='9';
        else m++;
        m--;
    }
    cout << n;
    return 0;
}
