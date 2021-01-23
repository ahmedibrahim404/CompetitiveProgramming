#include <iostream>

using namespace std;

int main(){
    int t;
    cin >>t;
    while(t--){
        int n, c0, c1, h;string str;
        cin >> n >> c0 >> c1 >> h;
        cin >> str;

        int zs=0, os=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0') zs++;
            else os++;
        }

        if(c0 > c1){

            cout << c1*os + min(c0*zs, (h+c1)*zs) << "\n";


        } else {

            cout << c0*zs + min(c1*os, (h+c0)*os) << "\n";

        }

    }
    return 0;
}
