#include <iostream>

using namespace std;
typedef long long ll;
int t;
ll b;
int main(){
    cin >> t;
    while(t--){
        cin >> b;
        int i=1;
        ll a=1, tot=0;
        while(a){
            a=(1<<i)-1;
            ll need=a*(a+1)/2;
            if(need<=b) b-= need, tot++;
            else break;
            i++;
        }
        cout << tot << endl;
    }
    return 0;
}
