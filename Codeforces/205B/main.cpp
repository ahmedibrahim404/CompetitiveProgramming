#include<bits/stdc++.h>
using namespace std;

long long n, ns[100000+9];
int main(){

    scanf("%lld", &n);
    for(int i=0;i<n;i++) scanf("%lld", &ns[i]);

    long long total=0, diff=0;
    for(int i=0;i<n-1;i++){

        if(ns[i] > ns[i+1]){
            if(ns[i]-ns[i+1] > 0){
                diff=ns[i]-ns[i+1];
            }
            total += (ns[i]-ns[i+1])-diff;
            diff +=(ns[i]-ns[i+1])-diff;
            ns[i+1]=ns[i];
        } else diff=0;

    }

    printf("%lld", total);

    return 0;
}
