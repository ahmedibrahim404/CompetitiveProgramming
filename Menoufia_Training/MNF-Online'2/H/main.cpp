#include <iostream>

using namespace std;

string a, b;
int main(){
    freopen("subin.in", "r", stdin);
    freopen("subout.out", "w", stdout);
    cin >> a >> b;
    int len=a.length();
    if(a.find(b) < len) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
