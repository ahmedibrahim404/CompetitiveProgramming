#include <iostream>

using namespace std;

int t, n, ns[100+3], no;
int main(){
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<=100;i++ )ns[i]=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++ ){
            scanf("%d",&no);
            ns[no]++;
        }

        int mex1=0, mex2=0;
        for(int i=0;i<=100;i++){
            if(ns[i]==0){
                break;
            }
            ns[i]--;
            mex1++;
        }
        for(int i=0;i<=100;i++){
            if(ns[i]==0){
                break;
            }
            ns[i]--;
            mex2++;
        }

        printf("%d\n", mex1+mex2);

    }
    return 0;
}
