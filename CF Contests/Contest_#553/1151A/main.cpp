#include <iostream>

using namespace std;

int n;
string s, to="ACTG";

int gett(int a, int b){
    if(a > b) swap(a, b);
    return min( abs(b-a) , abs( b-(a+26) ) );
}

int main(){

    cin >> n >> s;


    int cost=1e8;
    for(int i=0;i<n-3;i++){

        int tob=0;
        for(int j=0;j<4;j++){
            tob += gett(s[i+j]-'A', to[j]-'A');
        }
        if(tob < cost) cost=tob;

    }

    cout << cost << endl;

    return 0;
}
