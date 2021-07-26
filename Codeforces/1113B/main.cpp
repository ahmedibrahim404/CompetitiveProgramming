#include <iostream>
#include<algorithm>
using namespace std;

int n, ns[50000+9], total=0;

int is(int idx){
    int no=ns[idx];
    int sum=total;
    for(int i=1;i*i<=no;i++){
        if(i == 1) continue;
        if(no%i == 0){
            sum=min(sum, total - ns[0] - no + ns[0]*i + no/i);
            sum=min(sum, total - ns[0] - no + ns[0]*(no/i) + no/(no/i));
        }
    }

    return sum;

}

int main(){

    scanf("%d", &n);
    for(int i=0;i<n;i++){
         scanf("%d", &ns[i]);
         total += ns[i];
    }
    sort(ns, ns+n);


    int ans=total;
    for(int i=n-1;i>=0;i--){
        ans = min(ans, is(i));
    }

    printf("%d", ans);

    return 0;
}
