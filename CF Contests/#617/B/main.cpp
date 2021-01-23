#include <iostream>

using namespace std;
int t;
typedef long long ll;
ll s;
int main(){
    cin >> t;
    while(t--){
        cin >> s;
        ll tot=0;
        while(s){
            tot+=(s/10)*10;
            s=(s%10)+s/10;
            if(s<10) {tot+=s;break;}
        }
        cout << tot << endl;
    }
    return 0;
}
