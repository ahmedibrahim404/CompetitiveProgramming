#include <iostream>

using namespace std;
int a, b,c=0;
int s[10];
int main(){
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        int idx=0, no=i;
        while(no){
            s[idx++]=no%10;
            no/=10;
        }
        bool is=1;
        for(int j=0;j<idx/2;j++){
            if(s[j]!=s[idx-j-1]){
                is=0;
                break;
            }
        }
        if(is) c++;
    }
    printf("%d",c);
    return 0;
}
