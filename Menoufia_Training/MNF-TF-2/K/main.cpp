#include <iostream>

using namespace std;
int T, l;
char str[100000+3];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&l, str);
        if(str[l-1]=='n'&&str[l-2]=='o'&&str[l-3]=='s'){
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}
