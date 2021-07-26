#include<bits/stdc++.h>

using namespace std;
const int N=30000+3;int sq=174;

int n, q;
int sorted[N], ns[N];

int query( int st, int en, int val ){

    int stg=st/sq;
    int eng=en/sq;
    int ans=0;
    if(stg==eng){

        for(int i=st;i<=en;i++){

            ans += ns[i] > val;
        }

    } else {

        for(int i=st;i<(stg+1)*sq;i++){
            ans += ns[i] > val;
        }

        for(int i=eng*sq;i<=en;i++){
            ans += ns[i] > val;
        }

        for(int i=stg+1;i<eng;i++){
            ans += (i+1)*sq - ((lower_bound(sorted + i * sq, sorted+(i+1)*sq , val+1) - sorted));
        }

    }

    return ans;

}


int main(){
    scanf("%d",&n);
    sq=sqrt(n);
    for(int i=0;i<n;i+=sq){
        int k=0;
        for(; k<sq && i+k < n;k++){
            scanf("%d", ns + i + k);
            sorted[i+k] = ns[i+k];
        }
        sort(sorted+i, sorted+i+k);
    }


    scanf("%d",&q);
    while(q--){
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        printf("%d\n", query(a, b, c));
    }


    return 0;
}
