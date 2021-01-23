#include <iostream>

using namespace std;
int t, n;
int main(){

    cin >> t;
    while(t--){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int cur=n*(a-b);
        if(cur >= (c-d) && cur <= (c+d)){
             cout << "Yes\n";
             continue;
        }
        if(cur < c-d){
            if((c-d)-cur <= 2*b*n) cout << "Yes\n";
            else cout << "No\n";
            continue;
        }

        if(cur > c+d){
            cout << "No\n";
        }
    }

    return 0;
}
