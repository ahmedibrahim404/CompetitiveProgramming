#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, ll> pi;
int n, a, ps[11+3];
ll b;
pi cnt[11+3];

bool cpr(pi p2, pi p1){
    if(ps[p2.first] > ps[p1.first]) return 1;
    else if(ps[p2.first]==ps[p1.first]) return p2.second > p1.second;
    else return 0;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %lld",&a,&b);
        cnt[a].first=a;
        cnt[a].second += b;
        ps[a]++;
    }
    sort(cnt, cnt+12, cpr);
    for(int i=0;i<=11;i++){
        if(cnt[i].second) printf("G%d %lld\n", cnt[i].first, cnt[i].second);
    }
    return 0;
}
