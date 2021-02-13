#include<bits/stdc++.h>

using namespace std;

int t, x, y;

int main(){
    scanf("%d",&t);
    char str[100000+3];
    while(t--){
        scanf("%d%d",&x,&y);
        scanf("%s", str);
        int u=0, d=0, l=0, r=0;
        int len=strlen(str);
        for(int i=0;i<len;i++){
            u += (str[i]=='U');
            d += (str[i]=='D');
            l += (str[i]=='L');
            r += (str[i]=='R');
        }

        bool can=1;
        if(x > 0 && x > r) can=0;
        if(x < 0 && -1*x > l) can=0;

        if(y > 0 && y > u) can=0;
        if(y < 0 && -1*y > d) can=0;

        printf(can ? "YES\n" : "NO\n");


    }
    return 0;
}
