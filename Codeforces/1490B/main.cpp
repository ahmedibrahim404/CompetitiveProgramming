#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[3];for(int i=0;i<3;i++)ns[i]=0;
        for(int i=0;i<n;i++){int no;
            scanf("%d",&no);
            ns[no%3]++;
        }
        int mv=0;
        if(ns[0] > n/3) {
            int rem= - n/3 + ns[0];
            ns[0] -= rem;
            ns[1] += rem;
            mv += rem;
        }

        if(ns[1] > n/3) {
            int rem= - n/3 + ns[1];
            ns[1] -= rem;
            ns[2] += rem;
            mv += rem;

        }

        if(ns[2] > n/3) {
            int rem=- n/3 + ns[2];
            ns[2] -= rem;
            ns[0] += rem;
            mv += rem;

        }

                if(ns[0] > n/3) {
            int rem= - n/3 + ns[0];
            ns[0] -= rem;
            ns[1] += rem;
            mv += rem;
        }

        if(ns[1] > n/3) {
            int rem= - n/3 + ns[1];
            ns[1] -= rem;
            ns[2] += rem;
            mv += rem;

        }


        if(ns[2] > n/3) {
            int rem=- n/3 + ns[2];
            ns[2] -= rem;
            ns[0] += rem;
            mv += rem;

        }
        printf("%d\n", mv);

    }
    return 0;
}
