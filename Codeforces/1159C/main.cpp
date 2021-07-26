#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mx, mi=1e9;
int n, m, num, ns[100000+9], ms[100000+9];
map<int, int> mp1, mp2;
int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        ns[i]=num;
        mx=max(mx, num);
        mp1[num]++;
    }

    for(int i=0;i<m;i++){
        scanf("%d", &num);
        ms[i]=num;
        mi=min(mi, num);
        mp2[num]++;
    }

    if(mx > mi) return printf("-1\n"), 0;

    int im=0;

    sort(ns, ns+n, greater<int>());
    sort(ms, ms+m, greater<int>());

    ll total=0;

    for(int i=0;i<n;i++){

        while( mp2[ ms[im] ] == 0 && im < m ) {
            im++;
        }

        int cur=ns[i], remain=m-1;
        mp2[cur]=0;
        ll add=0;
        add += 1LL*cur*m;
        while(remain-- && im < m){
            if(mp2[ ms[im] ] > 0){
                add -= cur, add += ms[im], mp2[ ms[im] ]--;
                im++;
            } else im++;
        }


        total += add;

    }

    printf("%lld\n", total);


    return 0;
}
