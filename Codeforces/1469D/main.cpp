#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        //printf("%d\n", n-1);
        int lst=n;
        vector<pi> vi;
        for(int i=n-1;i>=3;i--){

            if((lst+i-1)/i >= i){
                lst=(lst+i-1)/i;
                vi.push_back({n, i});
            }

            vi.push_back({i, n});

        }

        while(lst > 1){
            lst = (lst+1)/2;
            vi.push_back({n, 2});
        }

        printf("%d\n", vi.size());
        for(auto &elem:vi){
            printf("%d %d\n", elem.first, elem.second);
        }

    }
    return 0;
}
