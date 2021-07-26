#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

long long int n;
int main(){
    scanf("%lld", &n);
    if (n == 1 || n == 3 || n == 4 || n == 6 || n == 9 || n == 12) {
        cout << 0 << endl;
        return 0;
    }
    int mod=n%3, mx;
    if(mod == 2){

        for(ll i=1e7;i>=1;i-=3){

            if(i*i*3+i <= n*2){
                mx=i;
                break;
            }

        }

    } else if (mod == 1){

        for(ll i=1e7+1;i>=1;i-=3){

            if(i*i*3+i <= n*2){
                mx=i;
                break;
            }

        }

    } else if (mod == 0){
        for(ll i=1e7+5;i>=1;i-=3){

            if(i*i*3+i <= n*2){
                mx=i;
                break;
            }

        }
    }

    cout << (int) ceil((double) mx/3) << endl;

    return 0;
}
