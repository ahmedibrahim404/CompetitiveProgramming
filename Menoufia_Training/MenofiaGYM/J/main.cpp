#include<bits/stdc++.h>
using namespace std;

int T, n, m, no, ns[1000+9][1000+9];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n, &m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&ns[i][j]);
            }
        }

        int sum=0;

        map<int, int> a, b;
        for(int i=1;i<n;i++){
            a.clear();
            b.clear();
            for(int j=0;j<m;j++){
                a[ ns[i-1][j] ]++;
                b[ ns[i][j] ]++;
                int mi=min(a[ ns[i-1][j] ], b[ ns[i-1][j] ]);
                a[ ns[i-1][j] ]-=mi, b[ ns[i-1][j] ]-=mi;
                sum += mi;

                mi=min(a[ ns[i][j] ], b[ ns[i][j] ]);
                a[ ns[i][j] ]-=mi, b[ ns[i][j] ]-=mi;
                sum += mi;


            }
        }

        printf("%d\n", sum);

    }
    return 0;
}
