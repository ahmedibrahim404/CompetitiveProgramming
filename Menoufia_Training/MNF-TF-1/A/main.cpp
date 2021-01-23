#include <iostream>

using namespace std;
int T, k;
string s;
int main(){
    freopen("coloring.in","r", stdin);
    cin >> T;
    int id=1;
    while(T--){
        cin >> s>> k;
        int c=0;
        int sz=s.length();
        for(int i=0;i<sz/2;i++) if(s[i] != s[sz-i-1]) c++;
        if(c <= k) cout << "Case " << id++ << ": YES"<<endl;
        else cout << "Case " << id++ << ": NO"<<endl;
    }
    return 0;
}
