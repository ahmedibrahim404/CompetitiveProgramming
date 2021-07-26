#include <iostream>

using namespace std;
bool is[ 100100+9 ];
string a, b;
int main(){

    for(int i=1;i<=316;i++) is[i*i]=1;
    cin >> a >> b;
    a += b;
    if(is[atoi(a.c_str())]) cout<< "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
