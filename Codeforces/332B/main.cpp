#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> ii;

ii arr[200000+9];
long long ns[200000+9];
int n, k;

bool cmp(ii p2, ii p1){

    if(p2.first > p1.first){
        return true;
    }

    if(p2.second < p1.second){
        return true;
    }

    return false;

}

int main(){

    scanf("%d %d", &n, &k);
    for(int i=1;i<=n;i++){
        scanf("%d", &ns[i]);
        ns[i] += ns[i-1];
    }

    // 3 6 1 1 6
    int idx=0;
    for(int i=1;i<=n-k+1;i++){
        arr[idx].first=ns[i+k-1]-ns[i-1];
        arr[idx].second=i;
        idx++;
    }

    sort(arr, arr+idx, cmp);
    int first=arr[0].second, second;
    for(int i=1;i<idx;i++){
        int mi=min(first, arr[i].second), mx=max(first, arr[i].second);
        if(mi + k - 1 < mx){
            second=arr[i].second;
            break;
        }
    }

    printf("%d %d", min(first, second), max(first, second));


    return 0;
}
