#include <iostream>

using namespace std;

int n, ns[200000+1];
int o=0, z=0;
int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &ns[i]);
        if(ns[i]) o++;
        else z++;
    }

    int t=0, t2=0;
    for(int i=0;i<n;i++){

        if(ns[i]) t++;
        else t2++;
        if(t==o || t2==z){
            printf("%d\n", i+1);
            break;
        }

    }

    return 0;
}
