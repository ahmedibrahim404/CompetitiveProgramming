#include <iostream>
#include<algorithm>
using namespace std;

int n, ns[26];
char str[10000000+7];
int main(){
    scanf("%d %s",&n, str);
    for(int i=0;i<n;i++) ns[ str[i]-'a' ]++;
    for(int i=0;i<26;i++){
        while(ns[i]--){
            printf("%c", i+'a');
        }
    }
    return 0;
}
