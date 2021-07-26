#include<bits/stdc++.h>

using namespace std;
int t, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ns[n+5];char str[n+1];
        scanf("%s", str+1);
        vector<int> vi;
        for(int i=1;i<=n;i++){
            if(str[i]=='L') ns[i]=0;
            else ns[i]=1;

            if(i > 1 && ns[i] == ns[i-1]){
                vi.push_back(i);
            }

        }

        for(int i=0;i<=n;i++){
            int ans=1;
            if(i >= 1 && ns[i] == 0){
                int idx=lower_bound(vi.begin(), vi.end(), i)-vi.begin();
                if(idx < vi.size() && vi[idx] == i){
                    ans += 1;
                } else if(idx-1 >= 0) {
                    ans += (i-vi[idx-1]+1);
                } else {
                    ans += i;
                }
            }

            if(i+1 <= n && ns[i+1] == 1){
                int idx=lower_bound(vi.begin(), vi.end(), i+2)-vi.begin();
                if(idx==vi.size()){
                    ans += n-i;
                } else {
                    ans += vi[idx]-i-1;
                }
            }

            cout << ans << " ";


        }

        cout << "\n";


    }
    return 0;
}
