#include <iostream>

using namespace std;
const int MAX=1000+3;
int T,n;
int ns[2];
int no;
int main(){
    cin >> T;
    while(T--){
        cin >> n;

        for(int i=0;i<2;i++)ns[i]=0;
        for(int i=0;i<n;i++){
            cin >> no;
            ns[ no ]++;
        }

        int re, k;
        if(ns[1]>ns[0]) re=1, k=ns[1]-(ns[1]%2); else re=0, k=ns[0];
        cout << k << endl;
        for(int i=0;i<k;i++){
            cout << re << " ";
        }
        cout << endl;


    }
    return 0;
}
