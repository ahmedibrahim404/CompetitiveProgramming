#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1 << 17 + 1;


int lg[N];
int sp[17][N];
int arr[N];
int n, m;
void init(){

    lg[0]=-1;
    for(int i=0;i<n;i++){
        lg[i+1] = lg[i] + !(i & (i+1));
        sp[0][i] = arr[i];
    }


}

void buildSP(){

    for(int j=1;(1<<j) < n;j++){
        for(int i=0;i+(1<<(j-1)) < n;i++){
            int a = sp[j-1][i];
            int b = sp[j-1][i+(1<<(j-1))];
            sp[j][i] = __gcd(a, b);
        }
    }

}

int query(int st, int en){
    int sz=en-st+1;
    int l = lg[sz];
    int a = sp[l][st];
    int b = sp[l][en - (1<<l) + 1 ];
    return __gcd(a, b);
}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    init();
    buildSP();

    map<int, ll> ans;

    for(int i=0;i<n;i++){

        int lst=i;
        while(lst < n){
            int l=i, r=n-1;
            int g = query(i, lst);


            int to=lst;
            while(r >= l){
                int mid=(l+r)>>1;
                if(query(i, mid) >= g) l = mid+1, to=mid;
                else r=mid-1;
            }
            ans[g] += 1LL*(to-lst+1);
            lst = to + 1;

        }


    }

    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        printf("%lld\n", ans[x]);
    }



    return 0;
}

