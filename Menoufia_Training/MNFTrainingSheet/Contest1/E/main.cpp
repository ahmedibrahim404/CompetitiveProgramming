#include<bits/stdc++.h>
using namespace std;
#define s second
#define f first
typedef long long ll;
const int MAX=2e5+9;
int as[MAX], bs[MAX], cs[MAX];
int n, k,a,b,c;

int main(){
    scanf("%d%d",&n,&k);
    int ta=0,tb=0,tc=0;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(b&&c) cs[tc++]=a;
        else if(b) as[ta++]=a;
        else if(c) bs[tb++]=a;
    }


    sort(as, as+ta);
    sort(bs, bs+tb);
    sort(cs, cs+tc);

    int pa=0, pb=0, pc=0;
    ll ans=0;
    while(k--){

        if(pa < ta && pb < tb){
            if(pc < tc){
                if(as[pa] + bs[pb] < cs[pc]){
                    ans+=1LL*as[pa] + 1LL*bs[pb];
//                    cout << "1TAKE " << 1LL*as[pa] << " AND " << bs[pb] << endl;
                    pa++, pb++;
                    continue;
                } else {
                    ans += 1LL*cs[pc];
//                    cout << "1TAKE " << cs[pc] << " " << pc << endl;
                    pc++;
                    continue;
                }
            } else {
                ans+=1LL*as[pa] + 1LL*bs[pb];
//                cout << "2TAKE " << 1LL*as[pa] << " AND " << bs[pb] << endl;
                pa++, pb++;
                continue;
            }
        } else if(pc < tc) {
            ans += 1LL*cs[pc];
//            cout << "2TAKE " << cs[pc] << endl;
            pc++;
            continue;
        } else {
            printf("-1\n");
            return 0;
        }

    }

    printf("%lld\n", ans);



    return 0;
}
