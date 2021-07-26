#include <iostream>

using namespace std;

int a, b;
char c;
int q0[150], q1[150], ns[10];
int main(){

    int idx=0;
    while(cin >> c){
        if(c == '?'){
            cin >> a >> b;
            q0[idx]=a, q1[idx++]=b;
        } else {
            for(int i=0;i<6;i++) cin >> ns[i];
            break;
        }
    }

    for(int i=0;i<idx;i++){
        printf("%lld\n", 1LL*ns[ q0[i]-1 ] * ns[ q1[i]-1 ]);
        fflush(stdout);
    }
    return 0;
}
