#include <iostream>

using namespace std;

int n, m, k;
int ns[1000+9];
int main(){

    scanf("%d %d %d", &n, &m, &k);

    for(int i=0;i<m+1;i++){
        scanf("%d", &ns[i]);
    }

    int res=0;
    for(int i=0;i<m;i++){

            int n1=ns[m], n2=ns[i];
            int cnt=0;

            while(n1 || n2){
                cnt += (n1&1) != (n2&1);
                n1 >>= 1;
                n2 >>= 1;
            }

            if(cnt <= k) res++;
    }

    printf("%d", res);

    return 0;
}
