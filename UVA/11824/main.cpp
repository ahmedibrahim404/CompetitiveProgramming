#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int t, ns[41];

long long power(int num, int pp){

    long long res=1;
    for(int i=0;i<pp;i++){
        res *= num;
    }
    return res;

}

int main(){

    scanf("%d", &t);

    while(t--){

        int i=0;
        while(cin >> ns[i]){
            if(ns[i] == 0) break;
            i++;
        }

        sort(ns, ns+i, greater<int>());
        long long ans=0;
        for(int j=0;j<i;j++) ans += power(ns[j], j+1);
        if(ans*2 > 5000000) printf("Too expensive\n");
        else printf("%lld\n", ans*2);

    }

    return 0;
}
