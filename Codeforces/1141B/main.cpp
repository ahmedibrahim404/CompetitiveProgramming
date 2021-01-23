#include <iostream>

using namespace std;

int n, a[200000+9];

int main(){

    scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    int mx=0;

    for(int i=0;i<n;i++){

        if(a[i]){

            int cos=1;
            int temp=i+1;
            while(temp >= 0){
                if(temp==n) temp=0;
                if(temp == i || a[temp]==0) break;
                cos++, temp++;
            }

            i += cos-1;
            mx=max(mx, cos);

        }


    }

    printf("%d", mx);

    return 0;
}
