#include <iostream>

using namespace std;
int T, N;
char str[1000+3];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%s",&N,str);
        int pre=str[0]-'a', cnt=1;
        for(int i=1;i<N;i++){
            if(abs((str[i]-'a')-pre) > 1) cnt++;
            pre=str[i]-'a';
        }
        printf("%d\n", cnt);
    }
    return 0;
}
