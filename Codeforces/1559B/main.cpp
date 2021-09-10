#include <iostream>

using namespace std;

int t, n;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);char s[n];
        scanf("%s", s);int st=(s[0] == 'R') ? 0 : 1; // red
        if(s[0] == '?'){
            int idx=0;
            while(idx < n && s[idx] == '?'){
                idx++;
            }
            if(idx < n){
                if(idx&1){
                    if(s[idx] == 'B') st=0;
                    else st=1;
                } else {
                    if(s[idx] == 'B') st=1;
                    else st=0;
                }
            }
        }

        if(st == 0) s[0] = 'R';
        else s[0] = 'B';
        for(int i=1;i<n;i++){
            if(s[i] == '?') {
                if(s[i-1] == 'R') s[i]='B';
                else s[i]='R';
            }
        }

        for(int i=0;i<n;i++) printf("%c", s[i]);
        printf("\n");


    }
    return 0;
}
