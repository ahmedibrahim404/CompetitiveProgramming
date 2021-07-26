#include <iostream>

using namespace std;

int T;
char str[100+9];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s", str);
        int c=1;
        for(int i=0;str[i];i++){
            if(isupper(str[i])) c++;
        }
        if(c > 7) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
