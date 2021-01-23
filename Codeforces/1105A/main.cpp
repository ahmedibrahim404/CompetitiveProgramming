#include <iostream>

using namespace std;

int n, cnt[101], a;
int mxcnt=0, mxnum;
int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d", &a);
        cnt[a]++;
        mxnum=max(mxnum, a);
    }

    int cntt=0, res=1e8;
    for(int i=1;i<=mxnum;i++){
        cntt=0;
        for(int j=1;j<=100;j++) if(abs(i-j) > 1) cntt += cnt[j]*(abs(j-i)-1);
        if(res > cntt)
            res=cntt, mxcnt=i;
    }


    printf("%d %d\n", mxcnt, res);


    return 0;
}
