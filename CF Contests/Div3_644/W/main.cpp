#include <iostream>

using namespace std;

int t, n;
int ns[55][55];
int cols[51], rows[51];
char str[51];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<51;i++) rows[i]=0, cols[i]=0;
        for(int i=0;i<n;i++){
            scanf("%s", str);
            for(int j=0;j<n;j++)
                ns[i][j]=str[j]-'0';

        }
        bool stop=0;
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
//                cout << i << " " << j << endl;
                if(ns[i][j]==1){
                    if(ns[i+1][j] || ns[i][j+1]) continue;
                    stop=1;
                    break;
                }

            }

            if(stop) break;

        }

        if(stop) printf("NO\n");
        else printf("YES\n");

    }
    return 0;
}
