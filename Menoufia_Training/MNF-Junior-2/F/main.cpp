#include <iostream>

using namespace std;

int t, cnt[26];
char str[50+3];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s", str);
        for(int i=0;i<26;i++) cnt[i]=0;
        int no=-1;
        bool is=0;
        for(int i=0;str[i];i++){
            if(str[i]-'0' <=9 && no==-1) no=str[i]-'0';
            else if(str[i]-'0' <= 9 && no != -1) {is=1;break;}
            else cnt[ str[i]-'a' ]++;
        }
        if(no == -1) is=1;
        int sum=no;
        if(!is){
            for(int i=0;i<26;i++){
                sum += cnt[i]*(i+1);
            }
        }
        if(is || (sum&1)) printf("NO\n"); else printf("YES\n");
    }
    return 0;
}
