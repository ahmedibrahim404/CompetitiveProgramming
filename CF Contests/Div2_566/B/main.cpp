#include <iostream>

using namespace std;

int h, w;
char ns[500+9][500+9];
int main(){
    scanf("%d %d", &h, &w);
    int cnt=0;
    for(int i=0;i<h;i++) {
            scanf("%s", ns[i]);
        for(int j=0;j<w;j++) if(ns[i][j] == '*') cnt++;
    }

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int cur=0;
            if(ns[i][j] == '*' && ns[i+1][j] == ns[i][j] && ns[i-1][j] == ns[i][j] && ns[i][j+1]==ns[i][j] && ns[i][j-1] == ns[i][j]){
                cur=5;
                for(int k=i+2;k<h;k++) if(ns[k][j]=='*') cur++; else break;
                for(int k=i-2;k>=0;k--) if(ns[k][j]=='*') cur++; else break;
                for(int k=j+2;k<w;k++) if(ns[i][k]=='*') cur++; else break;
                for(int k=j-2;k>=0;k--) if(ns[i][k]=='*') cur++; else break;
                if(cur == cnt ) return printf("YES\n"), 0;
            }
        }
    }

    printf("NO\n");

    return 0;
}
