#include<bits/stdc++.h>
using namespace std;
int T,N, a[100000+3];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        queue<int>q;
        for(int i=1;i<=N;i++) q.push(i);
        int i=1;
        while(!q.empty()){
            int fr=q.front();
            a[ fr ] =  i++;
            q.pop();
            if(!q.empty()){
                int fr2=q.front();
                q.pop();
                q.push(fr2);
            }
        }

        for(int i=1;i<=N;i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
