#include <iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, m, idx, ii=0;
ll ns[100+9], luck[31], sum=0;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%lld", &ns[i]);
    for(int i=0;i<m;i++){
        scanf("%d", &idx);
        idx--;
        luck[ii++]=ns[idx];
        ns[idx]=0;
    }

    for(int i=0;i<n;i++) sum += ns[i];
    ll presum=sum;

    sort(luck, luck+ii);
    for(int i=0;i<ii;i++){
        if(presum > luck[i]) presum += presum;
        else presum += luck[i];
    }

    sort(luck, luck+ii, greater<ll>());
    for(int i=0;i<ii;i++){
        if(sum > luck[i]) sum += sum;
        else sum += luck[i];
    }

    printf("%lld", max(presum, sum));

    return 0;
}
