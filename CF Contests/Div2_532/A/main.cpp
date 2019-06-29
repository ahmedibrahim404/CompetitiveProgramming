#include <iostream>

using namespace std;

int n, k, no, ns[100+9];
int main(){

    cin >> n >> k;

    int e=0, o=0;
    for(int i=1;i<=n;i++) {
        cin >> ns[i];
        if(ns[i] == -1) e++;
        else o++;
    }

    int mx=0;
    for(int b=-100;b<=100;b++){

        int xe=e, xo=o;
        for(int i=-100;i<=100;i++){

            int c=b+i*k;
            if(c >= 1 && c <= n){
                if(ns[c] == -1) xe--;
                else xo--;
            }

        }

        mx=max(mx, abs(xo-xe));

    }

    cout << mx << endl;

    return 0;
}
