#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int m, n;
vi a, b;
int main(){
    scanf("%d", &n);
    a=vi(n);

    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end());

    scanf("%d", &m);
    b=vi(m);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    sort(b.begin(), b.end(), greater<int>());

    int dis=a[0], i=0, s=0;
    long long total=0;

    while(i < m){
        total += b[i];
        dis--;
        if(dis == 0){
            dis=a[0];
            i+=3;
        } else i++;
    }


    printf("%lld", total);

    return 0;
}
