#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, N1, N2, a;
queue<int> v1, v2;

void solve(){

    int f=0;

    while(f < 100000 && v1.size() && v2.size()){

        int x=v1.front();
        v1.pop();
        int y=v2.front();
        v2.pop();


        queue<int> toput;

        if(x > y){
            v1.push(y);
            v1.push(x);
        } else {
            v2.push(x);
            v2.push(y);
        }

        f++;

    }

    if (v2.empty()) cout << f << " 1" << endl;
    else if (v1.empty()) cout << f << " 2" << endl;
    else cout << -1 << endl;



}

int main(){

    cin >> N;

    cin >> N1;
    while(N1--){
        cin >> a;
        v1.push(a);
    }


    cin >> N2;
    while(N2--){
        cin >> a;
        v2.push(a);
    }

    solve();
    return 0;
}
