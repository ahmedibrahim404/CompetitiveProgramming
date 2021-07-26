#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int n;
int ns[100000];
int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &ns[i]);



    for(int i=1;i<n-1;i++){

        int x1=-1, y1=-1, x2=-1, y2=-1;
        for(int j=0;j<i;j++){
            if(ns[j] > ns[i] && x1 == -1) x1=j;
            if(ns[j] < ns[i] && x2 == -1) x2=j;
            if(x1 != -1 && x2 != -1) break;
        }

        for(int j=i+1;j<n;j++){
            if(x1 == -1 && x2 == -1) break;
            if(ns[j] > ns[i] && y1 == -1) y1=j;
            if(ns[j] < ns[i] && y2 == -1) y2=j;
        }

        if(x1 != -1 && y1 != -1){
            return printf("3\n%d %d %d",x1+1, i+1, y1+1),0;
        }


        if(x2 != -1 && y2 != -1){
            return printf("3\n%d %d %d",x2+1, i+1, y2+1),0;
        }


    }

    printf("0\n");



    return 0;
}
