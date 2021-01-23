#include<bits/stdc++.h>

using namespace std;
const int MAX=400+1;

struct point {
    int x, y, val;
};

typedef pair<double, int> pi;

int n;
point ns[MAX];
vector<pi> vi;
const double EPS=1e-8;
int cum[MAX];
double slope(int i, int j){
    return ((double)(ns[i].y-ns[j].y))/((double)(ns[i].x-ns[j].x));
}
double pslope(int i, int j){
    return ((double)abs(ns[i].y-ns[j].y))/((double)abs(ns[i].x-ns[j].x));
}

int lower(double slope){

    int st=0, en=vi.size()-1;
    int ans=en+1;
    while(en>st){
        int mid=(st+en)>>1;
        if(vi[mid].first>=slope+EPS){
            ans=mid;
            en=mid-1;
        } else {
            st=mid+1;
        }
    }

    return ans;

}

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&ns[i].x, &ns[i].y, &ns[i].val);
    }

    int ans=1e9;
    for(int i=1;i<n;i++){
        int val=0;
        vi.clear();
        vi.push_back({pslope(i , 0), ns[0].val});
        for(int j=1;j<n;j++){
            if(j==i) continue;
            // from i => 0
            if(slope(i, j) > slope(i, 0)){
                // add
                val += ns[j].val;
            } else {
                // rem
                val -= ns[j].val;
            }
            vi.push_back({pslope(i, j), ns[j].val});
        }

        sort(vi.begin(), vi.end());

        int sz=vi.size();
        memset(cum, 0, sizeof cum);
        cum[0]=vi[0].second;
        for(int j=1;j<sz;j++){
            cum[i]=vi[i].second+cum[i-1];
        }


        double cur=slope(i, 0);
        for(int j=1;j<n;j++){
            if(i==j) continue;

            double nslope=slope(i, j);

            if(nslope>cur+EPS){
                // cur => nslope

                int idx1=lower(cur);
                int idx2=lower(nslope);
                if(idx1==vi.size()) continue;
                idx2--;
                if(idx2 > idx1 && idx2>=0){
                    val += 2*(cum[idx2]-(idx1?cum[idx1-1]:0));
                }

            } else {
                int idx1=lower(nslope);
                int idx2=lower(cur);
                if(idx2 > idx1 && idx1==vi.size()) continue;

                idx2--;
                if(idx2>=0){
                    val -= 2*(cum[idx2]-(idx1?cum[idx1-1]:0));
                }
                // nslope => cur
            }



            // point from i to j


            ans=min(ans, abs(val));

        }

    }

    printf("%d\n", ans);

    return 0;
}
