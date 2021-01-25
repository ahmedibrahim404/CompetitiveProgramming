#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n+3][n+3];
        int firR[10][n+3], lstR[10][n+3];
        memset(firR, -1, sizeof firR);memset(lstR, -1, sizeof lstR);
        int firC[10][n+3], lstC[10][n+3];
        memset(firC, -1, sizeof firC);memset(lstC, -1, sizeof lstC);

        int firstRow[10], firstCol[10], lastRow[10], lastCol[10];
        for(int i=0;i<10;i++) firstRow[i]=firstCol[i]=lastRow[i]=lastCol[i]=-1;

        char str[n+3];
        for(int i=0;i<n;i++){
            scanf("%s", str);
            for(int j=0;j<n;j++){
                int no=str[j]-'0';
                ns[i][j]=no;

                if(firstRow[no]!=-1) firstRow[no]=min(firstRow[no], i); else firstRow[no]=i;
                if(firstCol[no]!=-1) firstCol[no]=min(firstCol[no], j); else firstCol[no]=j;
                lastRow[no]=max(lastRow[no],i);lastCol[no]=max(lastCol[no], j);

                if(firR[no][i]==-1) {
                    firR[no][i]=j;
                }
                lstR[no][i]=j;

                if(firC[no][j]==-1) {
                    firC[no][j]=i;
                }
                lstC[no][j]=i;

//                cout << no << " " << firR[no][i] << " " << lstR[no][i] << " " << firstRow[no] << " " << lastRow[no] << "\n";


            }
        }

        int ans[10+3];
        memset(ans, 0, sizeof ans);
        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                for(int k=0;k<10;k++){

                int cur=k;
                // same row first
                int dis=0;
                if(firR[cur][i] != -1) dis=abs(firR[cur][i]-j);

                int idx=firstRow[cur];
                // i-th row TO idx-th row
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-i));

                idx=lastRow[cur];
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-i));

                dis=0;
                if(lstR[cur][i] != -1) dis=abs(lstR[cur][i]-j);

                idx=firstRow[cur];
                // i-th row TO idx-th row
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-i));

                idx=lastRow[cur];
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-i));

                // same column
                dis=0;
                if(firC[cur][j] != -1) dis=abs(firC[cur][j]-i);

                idx=firstCol[cur];
                // i-th row TO idx-th row
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-j));

                idx=lastCol[cur];
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-j));

                dis=0;
                if(lstC[cur][j] != -1) dis=abs(lstC[cur][j]-i);



                idx=firstCol[cur];
                // i-th row TO idx-th row
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-j));

                idx=lastCol[cur];
                if(idx != -1) ans[cur] = max(ans[cur], dis*abs(idx-j));

                }


            }

        }

        for(int i=0;i<10;i++) printf("%d ", ans[i]);
        printf("\n");

    }
    return 0;
}
