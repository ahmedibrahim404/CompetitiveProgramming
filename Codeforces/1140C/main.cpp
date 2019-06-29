#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
typedef long long ll;
int n, k;

pi a[300000+9];
priority_queue<int, vector<int>, greater<int>> q;

int main(){

    scanf("%d %d", &n, &k);
    ll ans=0;

    for(int i=0;i<n;i++){
        scanf("%d %d", &a[i].second, &a[i].first);
        ans=max(ans, 1LL*a[i].first * a[i].second);
    }

    sort(a, a+n);
    ll total=0;
    for(int i=n;i>=0;i--){

        q.push(a[i].second);
        total += a[i].second;

        if(q.size()>k){
            total-=q.top();
            q.pop();
        }

        ans=max(ans, total*a[i].first);

    }

    printf("%lld\n", ans);


    return 0;
}
