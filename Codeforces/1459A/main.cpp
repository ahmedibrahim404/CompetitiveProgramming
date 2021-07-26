#include <iostream>

using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string r, b;
        cin >> r >> b;
        int re=0, bl=0;
        for(int i=0;i<n;i++){
            if(r[i]-'0' > b[i]-'0')
                re++;
            else if(r[i]-'0' < b[i]-'0')
                bl++;
        }
        if(re>bl) cout << "RED\n";
        else if(re<bl) cout << "BLUE\n";
        else cout << "EQUAL\n";
    }

    return 0;
}
