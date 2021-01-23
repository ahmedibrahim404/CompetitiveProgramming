#include <iostream>

using namespace std;

int n, m, no; char str[1000+3];
int ans[1000][5];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++) ans[j][str[j]-'A']++;
    }

    int sum=0;
    for(int i=0;i<m;i++){
        scanf("%d",&no);
        int mx=0;
        mx=max(max(max(ans[i][0], ans[i][1]), max(ans[i][2], ans[i][3])), ans[i][4]);
        sum += no*mx;
    }

    printf("%d\n", sum);

    return 0;
}
