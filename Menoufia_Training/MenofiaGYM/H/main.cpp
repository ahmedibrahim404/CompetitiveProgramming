#include<bits/stdc++.h>
using namespace std;

int T;
char str[1000+9];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s", str);
        bool cant=0;
        int len=strlen(str);
        for(int i=0;i<len-1;i++){
            if(((str[i+1]-'a')-(str[i]-'a') == 1) || (str[i+1]=='a' && str[i]=='z'))continue;
            printf("NO\n");
            cant=1;
            break;
        }
        if(!cant) printf("YES\n");
    }
    return 0;
}
