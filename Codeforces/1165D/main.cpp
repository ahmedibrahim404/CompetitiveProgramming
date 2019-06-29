#include<bits/stdc++.h>
using namespace std;

int t, n;
vector<int> vi, vi2;
typedef long long ll;
bool check(){

    for(int i=0;i<n;i++){
        if(vi[i] != vi2[i]) return false;
    }

    return true;

}

int main(){
    scanf("%d", &t);
    while(t--){


        scanf("%d", &n);
        vi=vector<int>(n), vi2=vector<int>(n);
        for(int i=0;i<n;i++) scanf("%d", &vi[i]);


        sort(vi.begin(), vi.end());
        long long ans = 1LL* vi[0] * vi[n-1];

        int idx=0;
        for(long long i=2;i*i<=ans;i++){
            if(ans%i==0){
                if(idx >= n){
                    idx++;
                } else vi2[idx++]=i;

                if(i != ans/i){
                    if(idx >= n) {
                        idx++;
                    } else vi2[idx++]=ans/i;
                }
            }
        }

        sort(vi2.begin(), vi2.end());

        if(idx == n && check()){
            printf("%lld\n", ans);
        } else {
            printf("-1\n");
        }


    }
    return 0;
}
