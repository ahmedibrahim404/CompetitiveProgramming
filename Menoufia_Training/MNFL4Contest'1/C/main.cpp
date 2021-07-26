#include<bits/stdc++.h>
using namespace std;

int T, n, cnt[26], all[26];
char str[20+9];
typedef long long ll;
ll fact[21];
int main(){
    scanf("%d",&T);
    fact[1]=fact[0]=1;
    for(int i=2;i<=20;i++) fact[i] = fact[i-1]*i;
    while(T--){
        scanf("%d %s",&n, str);
        for(int i=0;i<26;i++) cnt[i]=0, all[i]=0;
        for(int i=0;i<n;i++){
            cnt[str[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            all[cnt[i]]++;
        }
        bool is=0, br=0;
        int total=0;
        vector<int> v;

		if(n % 2 == 0){
			for(int i = 0; i < 26; i++) {
				if(cnt[i] % 2 != 0) {
					br = 1;
					break;
				}
			}
		} else {
			int u = 0;
			for(int i = 0; i < 26; i++){
				if(cnt[i] % 2 == 1) u++;
			}
			if(u != 1) br = 1;
		}
        if(br){
            printf("0\n");;
            continue;
        }

        ll t=fact[n/2], tt=1;
        for(int i=0;i<26;i++){
            tt *= fact[ cnt[i]/2 ];
        }

        printf("%lld\n", t/tt);
    }
    return 0;
}
