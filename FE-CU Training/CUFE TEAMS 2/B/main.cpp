#include <iostream>

using namespace std;
const int MAX=100000+3;
int n;
int as[MAX], bs[MAX];

bool check(int sz){

    int ls=0, le=n-1;
    int rs=0, re=n-1;

    for(int i=0;i<n;i++){

        // as[i] => bs[i]

        if(i+sz-1 >= n) continue;
        int st1=as[i], st2=as[i+sz-1];
        int en1=bs[i], en2=bs[i+sz-1];

        st1=max(st1, st2);
        en1=min(en1, en2);

        if(en1>st1 && en1-st1+1 >= sz){
            return 1;
        }

    }

    return 0;

}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&as[i],&bs[i]);

    int st=1, en=n;
    int ans=1;
    while(en>=st){

        int mid=(st+en)>>1;

        if(check(mid)){
            st=mid+1;
            ans=mid;
        } else {
            en=mid-1;
        }

    }

    printf("%d\n", ans);

    return 0;
}
