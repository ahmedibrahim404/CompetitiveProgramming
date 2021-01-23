#include <iostream>

using namespace std;

int cnt[26];
char str[1000+3];
int main(){
    scanf("%s",str);
    int len=0;
    for(int i=0;str[i];i++){
         cnt[ str[i]-'a' ]++;
         len++;
    }

    int cc=0, ev=0;
    for(int j=0;j<26;j++){
        cc += (cnt[j]&1);
        ev += !(cnt[j]&1);
    }
    if(cc==1||cc==0) return printf("First\n"), 0;

    for(int i=0;i<len;i++){

        bool did=0;
        cc=0;
        for(int j=0;j<26;j++){
            if(!did && cnt[j] > 0 && !(cnt[j]&1)){
                cnt[j]--;
                did=1;
            }
            cc += (cnt[j]&1);
        }

        if(!did){
            for(int j=0;j<26;j++){
                if(cnt[j]){
                    cnt[j]--;
                    cc--;
                    break;
                }
            }
        }

        if(cc==0 || cc==1){
            if((i&1)) return printf("First"),0;
            else return printf("Second"), 0;
        }



    }

    return 0;
}
