#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=200000+3;
int n;ll ns[MAX], pref[MAX];;
map<ll, int> cnt;
int main(){
    scanf("%d",&n);
    cnt.clear();
    int num=0;
    cnt[0]=1;
    for(int i=0;i<n;i++){
        scanf("%lld",&ns[i]);
    }
    for(int i=0;i<n;i++){
        pref[i]=ns[i];
        if(i) pref[i] += pref[i-1];
        if(cnt.find(pref[i]) != cnt.end()){
            num++;
            pref[i]=ns[i];
            cnt.clear();
            cnt[0]=1;

        }
        cnt[ pref[i] ]=1;
    }
    cout << num;
    return 0;
}
