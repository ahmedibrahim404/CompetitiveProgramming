#include <iostream>

using namespace std;
typedef long long ll;

int n, m;
int fir[51][51], sec[51][51];

int main(){

    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &fir[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &sec[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(i && fir[i-1][j] >= fir[i][j] ){
                int temp=sec[i][j];
                sec[i][j]=fir[i][j];
                fir[i][j]=temp;


                if(fir[i-1][j] >= fir[i][j] || sec[i-1][j] >= sec[i][j]){
                    printf("Impossible\n");
                    return 0;
                }

            }

            if(j && fir[i][j-1] >= fir[i][j] ){
                int temp=sec[i][j];
                sec[i][j]=fir[i][j];
                fir[i][j]=temp;

                if(fir[i][j-1] >= fir[i][j] || sec[i][j-1] >= sec[i][j]){
                    printf("Impossible\n");
                    return 0;
                }

            }

            if(i && sec[i-1][j] >= sec[i][j] ){
                int temp=fir[i][j];
                fir[i][j]=sec[i][j];
                sec[i][j]=temp;

                if(sec[i-1][j] >= sec[i][j] || fir[i-1][j] >= fir[i][j]){
                    printf("Impossible\n");
                    return 0;
                }

            }

            if(j && sec[i][j-1] >= sec[i][j] ){
                int temp=fir[i][j];
                fir[i][j]=sec[i][j];
                sec[i][j]=temp;

                if(sec[i][j-1] >= sec[i][j] || fir[i][j-1] >= fir[i][j]){
                    printf("Impossible\n");
                    return 0;
                }

            }

        }
    }

    printf("Possible\n");

    return 0;
}
