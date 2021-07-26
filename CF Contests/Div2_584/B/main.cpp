#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int n;
char str[100+3];
int a[100+3], b[100+3], here[5000+3];
pi st[100+3];
int main(){
    scanf("%d%s",&n,str);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        if(str[i]=='1') st[i].first=0, st[i].second=b[i]-1;
        else st[i].first=b[i], st[i].second=b[i]+a[i]-1;
    }
    int cnt=0, mx=0;
    while(1){
        if(cnt==100) break;
        for(int i=0;i<n;i++){
            for(int j=st[i].first;j<=st[i].second;j++) here[j]++;
            st[i].first=st[i].second+a[i]+1;
            st[i].second=st[i].first+a[i]-1;
        }
        cnt++;
    }

    for(int i=0;i<5000;i++){
        if(here[i] > mx)mx=here[i];
    }

    printf("%d\n", mx);

    return 0;
}
