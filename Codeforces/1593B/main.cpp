#include <iostream>
using namespace std;
typedef long long ll;
int k(ll n){
        int c1=0, c2=0, c3=0, c4=0, d1=0, d2=0, d3=0, d4=0;
        while(n){
            int dig = (int) (n%10);
            if(dig == 0) c1++;
            else d1++;

            if(c1 == 2) return d1;

            if(dig == 5 && c2 == 0) c2++;
            else if(dig == 2 && c2 == 1) return d2;
            else d2++;

            if(dig == 0 && c3 == 0) c3++;
            else if(dig == 5 && c3 == 1) return d3;
            else d3++;

            if(dig == 5 && c4 == 0) c4++;
            else if(dig == 7 && c4 == 1) return d4;
            else d4++;

            n=n/10;
        }

        return 1000;
}

int main(){
    int t;cin >>t;
    while(t--){
        ll n;cin >> n;
        cout << k(n) << endl;
    }

    return 0;
}
