#include <iostream>

using namespace std;
typedef long long ll;
const int MAX=500000;
int n;
ll no;

int main(){
    cin >> n;
    ll pre=0, a=0;
    for(int i=0;i<n;i++){
        cin >> no;
        pre += no;
        if(pre<0) a=max(a, -pre);
    }
    cout << a;
    return 0;
}
