#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int>pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
int n;
vpi total;
vi nums;

bool cmpr(pi p2, pi p1){

    if(p1.first != p2.first){
        return p2.first < p1.first;
    }

    return p2.second < p1.second;

}

int main(){
    scanf("%d",&n);
    total=vpi(n), nums=vi(n);

    for(int i=0;i<n;i++) scanf("%d", &total[i].first);
    for(int i=0;i<n;i++) scanf("%d", &total[i].second);

    sort(total.begin(), total.end(), cmpr);
    int pre=-1, idx=-1;
    for(int i=0;i<n;i++){

        if(total[i].first != pre){
            idx++;
            nums[idx]=i;
            pre=total[i].first;
        }

        if(i) total[i].second += total[i-1].second;
    }

//    for(int i=0;i<n;i++){
//        cout << total[i].first << " " << total[i].second << endl;
//    }


    long long mi=1e16;
    for(int i=0;i<=idx;i++){

        int start=nums[i], last=(i == idx) ? n-1 : nums[i+1]-1;
        int len=last-start+1;
        int need=n-(2*len-1);

        long long tot=0;
        if(i != idx){
            need -= n-last-1;
            tot += total[n-1].second - total[last].second;
        }

        if(need > 0){
            vector<int> mii(start);
            int j=start-1, idxx=0;
            while(j > 0){
                mii[idxx++]=(total[j].second-total[j-1].second);
                j--;
            }
                mii[idxx++]=(total[0].second);
            sort(mii.begin(), mii.end());
            for(int k=0;k<need;k++){
                tot += mii[k];
            }
        }

//        if(need != 0) tot += total[ need-1 ].second;
        if(tot < mi){
            mi=tot;
        }

    }

    printf("%lld", mi);

    return 0;
}
