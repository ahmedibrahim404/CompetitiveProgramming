#include <iostream>

using namespace std;

int n, k, num;
int ns[100000+9], cnt[100000+9];
int main(){
    scanf("%d %d", &n, &k);

    int pre=-1, idx=0;;
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        if(num == pre) continue;
        else {
            pre=num;
            ns[idx++]=num;
        }
    }

    for(int i=1;i<=k;i++) cnt[i]=idx;

    for(int i=0;i<idx;i++){

        if(i == 0 || i == idx-1){
            cnt[ ns[i] ]--;
            continue;
        }

        if( ns[ i+1 ] == ns[ i-1 ] ) cnt[ ns[i] ]--;
        cnt[ ns[i] ]--;


    }

    int mn=1;
    for(int i=1;i<=k;i++){
        if(cnt[i] < cnt[mn])mn=i;
    }

    printf("%d", mn);
    return 0;
}
