#include <iostream>

using namespace std;

string s;
int ns[10];
int main(){
    ns[0]=1, ns[1]=6, ns[2]=1, ns[3]=2, ns[4]=2, ns[5]=3, ns[6]=1, ns[7]=4, ns[8]=0, ns[9]=1;
    for(int i=0;i<=9;i++) ns[i]++;

    cin >> s;
    int res=1;
    for(int i=0;i<s.length();i++){
        res *= ns[ s[i] - '0' ];
    }

    cout << res << endl;

    return 0;
}
