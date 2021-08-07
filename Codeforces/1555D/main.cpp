#include <iostream>

using namespace std;

int n, m;
string str;
int main(){
    cin >> n >> m;
    cin >> str;

    int ns[n+1][3] = {0};
    for(int i=0;i<n;i++){
        int c=str[i] -'a';
        ns[i][c]++;
        for(int j=0;j<3;j++) if(i-3 >= 0) ns[i][j] += ns[i-3][j];
    }

    while(m--){
        int a, b;
        scanf("%d %d",&a,&b);
        a--, b--;

        if(b - a + 1 == 1){
            printf("0\n");
            continue;
        } else if(b - a + 1 == 2) {
            if(str[a] != str[b]) printf("0\n");
            else printf("1\n");
            continue;
        }

        int na=a, nb=b;

        while(na%3 != 0) na++;
        while(nb%3 != 0) nb--;
        int f1[3];
        if(nb >= na - 3) for(int j=0;j<3;j++) f1[j] = ns[nb][j] - (na-3 >= 0 ? ns[na-3][j] : 0);



        na=a, nb=b;
        while(na%3 != 1) na++;
        while(nb%3 != 1) nb--;
        int f2[3];
        if(nb >= na - 3) for(int j=0;j<3;j++) f2[j] = ns[nb][j] - (na-3 >= 0 ? ns[na-3][j] : 0);




        na=a, nb=b;
        while(na%3 != 2) na++;
        while(nb%3 != 2) nb--;
        int f3[3];
        if(nb >= na - 3) for(int j=0;j<3;j++) f3[j] = ns[nb][j] - (na-3 >= 0 ? ns[na-3][j] : 0);

        int tot = n+1;

        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                for(int c=0;c<3;c++){
                    if(a == c || a == b || b == c) continue;
                    int ans=0;

                    if(!a) ans += f1[1] + f1[2];
                    if(!b) ans += f1[0] + f1[2];
                    if(!c) ans += f1[0] + f1[1];


                    if(a == 1) ans += f2[1] + f2[2];
                    if(b == 1) ans += f2[0] + f2[2];
                    if(c == 1) ans += f2[0] + f2[1];

                    if(a == 2) ans += f3[1] + f3[2];
                    if(b == 2) ans += f3[0] + f3[2];
                    if(c == 2) ans += f3[0] + f3[1];

                    tot=min(ans, tot);
                }
            }
        }

        printf("%d\n", tot);


    }


    return 0;
}
