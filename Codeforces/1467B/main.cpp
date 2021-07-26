#include <iostream>

using namespace std;

int t, n;
int ns[300000+3];

int isValley(int i) {
    return (i > 0 && i < n - 1 && ns[i] < ns[i - 1] && ns[i] < ns[i + 1]);
}

int isHill(int i) {
    return (i > 0 && i < n - 1 && ns[i] > ns[i - 1] && ns[i] > ns[i + 1]);
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        int is[n]={};
        for(int i=0;i<n;i++){
            scanf("%d",&ns[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            if (isHill(i) || isValley(i))
                is[i] = 1, cnt++;
        }

        int ans = cnt;
        for (int i = 1; i < n - 1; i++) {
            int temp = ns[i];
            ns[i] = ns[i - 1];
            ans = min(ans, cnt - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
            ns[i] = ns[i + 1];
            ans = min(ans, cnt - is[i - 1] - is[i] - is[i + 1] + isHill(i - 1) + isValley(i - 1) + isHill(i) + isValley(i) + isHill(i + 1) + isValley(i + 1));
            ns[i] = temp;
        }

        printf("%d\n", ans);



    }
    return 0;
}
