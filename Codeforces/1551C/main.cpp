#include<bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string str;
        int cnt[5][n];
        for(int i=0;i<5;i++) for(int j=0;j<n;j++) cnt[i][j]=0;
        for(int i=0;i<n;i++){
            cin >> str;
            int len=str.length();
            for(int j=0;j<len;j++) cnt[ str[j]-'a' ][i]++;
            for(int j=0;j<5;j++) cnt[j][i] = 2*cnt[j][i]-len;
        }

        int mx=0;
        for(int i=0;i<5;i++){
            sort(cnt[i], cnt[i]+n, greater<int>());
            int can=0, tot=0;
            for(int j=0;j<n;j++){
                tot += cnt[i][j];
                if(tot > 0) can=j+1;
            }
            mx=max(mx, can);
        }

        printf("%d\n", mx);

    }
    return 0;
}
