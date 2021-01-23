#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int n, k, ns[300000+9];
pi c[300000+9];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&ns[i]);
        if(i) c[i].first=ns[i]-ns[i-1], c[i].second=i;
    }

    k--;
    int l=1, r=n-1;
    int has=k-1;
    while(has--){
        if(c[l].first > c[r].first) l++;
        else r--;
    }



    cout << ns[r]-ns[l-1] << endl;

    return 0;
}
