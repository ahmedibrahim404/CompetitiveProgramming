#include <iostream>

using namespace std;

int n, m, no;
string s;
int main(){
    cin >> n >> m;
    int st=1, en=n;
    while(m--){
        bool is=0;
        for(int i=0;i<4;i++){
            cin >> s;
            if(i==2){
                if(s[0]=='l') is=1;
            }
        }
        cin >> no;
        if(is) en=min(en, no-1);
        else st=max(st, no+1);

        if(st > en) {
            cout << "-1" << endl;
            return 0;
        }

    }

    cout << en-st+1 << endl;
    return 0;
}
