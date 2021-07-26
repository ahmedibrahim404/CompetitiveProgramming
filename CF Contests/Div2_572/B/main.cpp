#include <iostream>
#include<algorithm>
using namespace std;
int n, a[100000+9];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a, a+n);
    bool cant=false;
    for(int i=0;i<n;i++){
        int pre=(i==0?n-1:i-1), nex=(i==n-1?0:i+1);
        if(a[pre]+a[nex] <= a[i]) {cant=true;break;}
    }
    if(!cant){
        printf("YES\n");
        for(int i=0;i<n;i++)printf("%d ", a[i]);
    } else {
        cant=false;
        swap(a[n-1], a[n-2]);
        for(int i=0;i<n;i++){
            int pre=(i==0?n-1:i-1), nex=(i==n-1?0:i+1);
            if(a[pre]+a[nex] <= a[i]) {cant=true;break;}
        }
        if(!cant){
        printf("YES\n");
        for(int i=0;i<n;i++)printf("%d ", a[i]);
        } else printf("NO");
    }
    return 0;
}
