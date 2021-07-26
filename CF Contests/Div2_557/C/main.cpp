#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int n, k, num;

vector<pi> vi(100000+9);
int main(){

    scanf("%d %d", &n, &k);

    for(int i=0;i<100000+8;i++) {
        vi[i].first=-1, vi[i].second=-1;
    }

    for(int i=0;i<k;i++){
        scanf("%d", &num);
        num--;
        if(vi[num].first == -1) vi[num].first=i;
        vi[num].second=i;
    }

    int ps=0;
    for(int i=0;i<n;i++){
        if(vi[i].first == -1) ps++;
        if(i && !(vi[i-1].second > vi[i].first && vi[i].first != -1 && vi[i-1].second != -1) ) ps++;
        if(i != n-1 && !(vi[i+1].second > vi[i].first && vi[i].first != -1 && vi[i+1].second != -1) ) ps++;
    }

    printf("%d", ps);



    return 0;
}
