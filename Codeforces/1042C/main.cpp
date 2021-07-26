#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll as[200000+9];
int zeros[200000+9], negs[200000+9];
ll mxneg=-1e10, mineg=0;
int mxnegi=0, minegi=0;

int main(){

    scanf("%d", &n);

    int zero=0, neg=0, remain=n;
    for(int i=0;i<n;i++){
        scanf("%lld", &as[i]);
        if(as[i] == 0) zeros[ zero++ ]=i;
        if(as[i] < 0){
            negs[ neg++ ]=i;
            if(as[i] > mxneg){
                mxneg = as[i];
                mxnegi=i;
            }

            if(as[i] < mineg){
                 mineg=as[i];
                 minegi=i;
            }
        }
    }

    bool used=false;


    if(neg%2){
        as[ mxnegi ]=0;
        zeros[ zero++ ] = mxnegi;
    }


    for(int i=0;i<zero-1;i++){
        int idx=i+1;
        printf("1 %d %d\n", zeros[i]+1, zeros[i+1]+1);
        as[zeros[i]]=-1e10;
        as[zeros[i+1]]=0;
        remain--;
    }

    if(zero > 0 && remain > 1) {
        printf("2 %d\n",  zeros[zero-1] +1);
        as[ zeros[zero-1] ]=-1e10;
        used=true;
    }

    for(int i=0;i<n-1;i++){
        if(as[i] == -1e10) continue;
        int idx=i+1;
        while(as[idx] == -1e10){
            idx++;
        }
        if(idx >= n) continue;
        printf("1 %d %d\n", i+1, idx+1);
        remain--;
        as[i] = -1e10;
    }

    return 0;
}
