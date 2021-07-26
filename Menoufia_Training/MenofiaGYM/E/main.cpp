#include <iostream>

using namespace std;

int T, n, m, price[26], total=0;
char str[1000+9], pri[1000+9], to[26];
int main(){
    scanf("%d",&T);
    while(T--){
        total=0;
        scanf("%d %d %s %s %s",&n, &m, str, pri, to);
        for(int i=0;i<26;i++) price[i]=1e5;
        for(int i=0;str[i];i++){
            price[ str[i]-'a' ]=min(price[str[i]-'a'], pri[i]-'0');
        }

        bool cant=0;
        for(int i=0;i<m;i++){
            if(price[to[i]-'a']==1e5){
                printf("-1\n");
                cant=1;
                break;
            }
            total += price[to[i]-'a'];
        }

        if(!cant)
        printf("%d\n", total);

    }
    return 0;
}
