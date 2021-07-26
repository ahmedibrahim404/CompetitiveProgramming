#include <iostream>

using namespace std;

int n;
int a[2000+9], ns[2000+9], as;

int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &as);
        ns[i]=as;
        a[as]++;
    }

    for(int i=2005;i>=0;i--){
        a[i] += a[i+1];
    }

    for(int i=0;i<n;i++){

        printf("%d ", a[ns[i]+1]+1);

    }

    printf("\n");

    return 0;
}
