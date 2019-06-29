#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int n, d, a[200000+9], b[200000+9];
map< pi, int > mp;

int mod(int a, int b) {
    int c = a % b;
    if(c < 0) return c+b;
    return c;
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n;i++) scanf("%d", &b[i]);

    int mx=0, add=0;
    for(int i=0;i<n;i++){

        int xb=b[i], xa=a[i];

        if(xa == 0 && xb == 0) add++;
        if(xa == 0) continue;

        int g=__gcd(xa, xb);

        mp[ { xb/g, xa/g } ]++;

        if(mp[ { xb/g, xa/g } ] > mx)
            mx = mp[ { xb/g, xa/g } ];

    }

    printf("%d\n", mx+add);


    return 0;
}
