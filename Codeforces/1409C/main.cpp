#include <iostream>

using namespace std;
int t, n, x, y;

int mi, st;

void check(int fir, int no){
    int aval=(no/fir)-1;
    if(aval == n-2){
        if(mi > y) mi=y, st=fir;
    } else if(aval < n-2){
        int need=(n-2)-aval;
        int can=(x-1)/fir;
        if(can >= need){
            if(mi > y) mi=y, st=fir;
        } else {
            if(mi >  y + (need-can)*fir) mi=y + (need-can)*fir, st=fir;
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        int no=(y-x);
        mi=2e9;st=0;
        for(int i=1;i*i<=no;i++){

            if(no%i!=0) continue;
            int fir=i;
            check(fir, no);

            int sec=no/i;
            check(sec, no);

        }

        while(n--){
            cout << mi << " ";
            mi -= st;
        }

        cout << "\n";

    }
    return 0;
}
