#include <iostream>

using namespace std;

int N, ns[100000+9], Q,no;

int bs(int num, int st=0, int en=N-1){

    if(st>en) return -2;

    int mid=(st+en)>>1;
    if(ns[mid]==num)return mid;
    if(ns[mid]>num){
        return bs(num, st, mid-1);
    } else {
        return bs(num, mid+1, en);
    }

}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&ns[i]);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&no);
        printf("%d\n" , bs(no)+1);
    }
    return 0;
}
