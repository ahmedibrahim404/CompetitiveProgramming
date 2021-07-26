#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int primeFactors(int n){
    int p=0;
    while (n % 2 == 0){
        n = n/2;
        p++;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2){
        while (n % i == 0){
            n = n/i;
            p++;
        }
    }

    if (n > 2) p++;
    return p;
}

int t;



int main(){
    scanf("%d",&t);
    while(t--){
        int a, b, k;
        scanf("%d%d%d",&a,&b,&k);

        if(b > a) swap(b, a);

        if(k == 1) {

            if(a%b == 0 && a != b){
                printf("YES\n");
            } else printf("NO\n");

            continue;

        }

        int tot = primeFactors(a) + primeFactors(b);
        if(tot >= k) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
