#include <iostream>

using namespace std;

string st;
int main(){

    int no=0;
    long long ans=0;
    while(getline(cin, st)){
        if(st.empty()) break;
        if(st[0]=='+') no++;
        else if(st[0]=='-')no--;
        else {

            int lene=st.length();
            int i;
            for(i=0;i<lene;i++){
                if(st[i]==':') break;
            }
            ans += 1LL*no*(lene-i-1);
        }
    }
    cout << ans << endl;
    return 0;
}
