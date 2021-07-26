#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX=1000+3;
const int OO=1e9;
int dp[MAX][2];
int l[MAX], r[MAX], cnt[MAX];
int n, m;
set<int> st;
vector<int> ans;

int main(){
    scanf("%d",&n);
    memset(dp, -1, sizeof dp);
    for(int i=0;i<n;i++) {
        scanf("%d%d",&l[i],&r[i]);
    }

    scanf("%d",&m);

    int no;
    for(int i=0;i<m;i++){
        scanf("%d",&no);
        st.insert(no);
        for(int j=0;j<n;j++){
            if(no>=l[j] && no<=r[j]){
                 cnt[j]++;
            }
        }
    }


    bool is=1;
    for(int i=0;i<n;i++){
        if(cnt[i]>2){
            is=0;
            break;
        }
    }



    if(is==0){
        printf("impossible\n");
        return 0;
    }

    bool rr;
    for(int i=0;i<n;i++){
        is = (r[i]==l[i+1]);
        rr = (st.find(r[i])!=st.end());
        if(is && !rr){
            if(cnt[i] < 2 && cnt[i+1] < 2){
                st.insert(r[i]);
                ans.push_back(r[i]);
                cnt[i]++;
                cnt[i+1]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(cnt[i]<2){
            for(int j=l[i]+1;j<r[i];j++){
                if(st.find(j)==st.end()){
                    st.insert(j);
                    ans.push_back(j);
                    cnt[i]++;
                    if(cnt[i]==2) break;
                }
            }
        }
    }

    int sz=ans.size();
    printf("%d\n", sz);
    for(int i=0;i<sz;i++){
        if(i==0) printf("%d", ans[i]);
        else printf(" %d", ans[i]);
    }



    return 0;
}
