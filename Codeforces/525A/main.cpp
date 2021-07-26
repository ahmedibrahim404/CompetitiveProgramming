#include<bits/stdc++.h>
using namespace std;

int n;
char ns[200000+9];
int has[26];

int main(){
    scanf("%d %s", &n, ns);
    int all=0;
    for(int i=0;i<2*n-2;i++){
        if(i%2){
            if(has[ tolower(ns[i])-'a' ]) has[ tolower(ns[i])-'a' ]--;
            else all++;
        } else {
            has[ ns[i]-'a' ]++;
        }
    }

    printf("%d", all);

    return 0;
}
