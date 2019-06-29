#include <iostream>

using namespace std;

int n, k;
char ns[100+9];
int to[100+9];
int main(){
    scanf("%d %d %s", &n, &k, ns);

    int c=1;
    for(int i=n;i>=1;i--){
        to[i]+=(c++);
    }

    for(char i='a';i<='z';i++){

        int cnt=0, pre=-1;
        for(int j=n-1;j>=0;j--){

            if(ns[j]==i){

                if(pre != -1){

                    for(int k=)

                }

                pre=j;
            }

        }

    }

    for(int i=1;i<=n;i++) cout << i << " " << to[i] << endl;


    return 0;
}
