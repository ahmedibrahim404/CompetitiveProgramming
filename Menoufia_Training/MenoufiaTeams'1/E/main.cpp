#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        n--;
        int a;
        cin >> a;
        int no;
        int tot=a;
        while(n--){
            cin >> no;
            a = __gcd(a, no);
            tot += no;
        }


        cout << a << " " << tot/a << "\n";

    }


    return 0;
}
