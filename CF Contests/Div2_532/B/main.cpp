#include <iostream>

using namespace std;
int n, m;
int a[100000+9], no;
int main(){

    scanf("%d %d", &n, &m);
    int took=0;
    for(int i=0;i<m;i++){
        scanf("%d", &no);
        no--;
        a[no]++;
        if(a[no] == 1) took++;

        if(took == n){
            for(int j=0;j<n;j++){
                a[j]--;
                if(a[j] == 0) took--;
            }
            printf("1");
        }
        else printf("0");
    }

    return 0;
}
