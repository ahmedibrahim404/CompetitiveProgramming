#include<bits/stdc++.h>
using namespace std;

int n, m;
int qus[1000+9], took[1000+9];
pair< int, pair<int, int> > ps[10000+9];
long long total=0;
int main(){
    scanf("%d", &n);
    int mx=0;
    for(int i=0;i<n;i++) took[i]=-1;
    for(int i=0;i<n;i++){
        scanf("%d", &qus[i]);
        if(qus[i] > qus[mx]) mx=i;
    }

    took[mx]=mx;

    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &ps[i].second.first, &ps[i].second.second, &ps[i].first);
        ps[i].second.first--;
        ps[i].second.second--;
    }

    sort(ps, ps+m);

    for(int i=0;i<m;i++){
        int from=ps[i].second.first, to=ps[i].second.second, u=ps[i].first;
        if(qus[from] > qus[to] && took[to] == -1){
            took[to]= from;
            total += u;
        }
    }

    for(int i=0;i<n;i++){
        if(took[i] == -1) return printf("-1\n", i), 0;
    }

    printf("%lld", total);



    return 0;
}
