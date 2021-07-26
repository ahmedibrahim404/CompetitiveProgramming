#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d;
    d.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]>d[d.size()-1])
        d.push_back(a[i]);
        else{
            int idx=lower_bound(d.begin(), d.end(), a[i])-d.begin();
            if(idx==n) continue;
            d[idx]=a[i];
        }
    }

    return d.size();

}
int n, no;
vector<int> vi;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&no);
        vi.push_back(no);
    }
    printf("%d\n", lis(vi));
    return 0;
}
