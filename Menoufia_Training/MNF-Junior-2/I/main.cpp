#include <iostream>

using namespace std;

string st;
char str[12]="icpcmenofia";
int main(){
    int idx=0;
    cin >> st;
    int len=st.length(), c=0;
    for(int i=0;i<len;i++){
        if(st[i]==str[idx]){
            idx++;
        }
        if(idx == 11) idx=0, c++;
    }
    cout << c << endl;
    return 0;
}
