#include <iostream>
#include <string.h>
using namespace std;
const int MAX=400+3;
char s[MAX], t[MAX];
int main(){
    scanf("%s %s",s,t);
    int l1=strlen(s), l2=strlen(t), total=0;;
    int mn=1e5;
    for(int i=0;i<l1;i++){
        int cc=0, cnt=0;
        for(int j=i;j<l1;j++){
            if(s[j]==t[cc]) cc++;
            cnt++;
            if(cc==l2) break;
        }
        if(cc==l2){if(cnt < mn) mn=cnt;}
    }
    if(mn==1e5) printf("-1");
    else printf("Yes\n%d", mn);
    return 0;
}
