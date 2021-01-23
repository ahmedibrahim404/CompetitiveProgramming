#include <iostream>
#include <cstring>
using namespace std;

char str[100+3];
int main(){
    scanf("%s", str);
    int changed=-1;
    int f=-1, s=-1;
    int len=strlen(str);
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(str[i]-'0' > str[j]-'0'){
                if((str[j]=='0'&&i==0)) continue;
                if(i > changed) f=i, s=j;
                else if(i==changed && str[j]-'0' > str[s]-'0') s=j;
            }
        }
    }
    if(f!=-1&&s!=-1){
        swap(str[f], str[s]);
        printf("%s", str);
    } else
    printf("-1\n");
    return 0;
}
