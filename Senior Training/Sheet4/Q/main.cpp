#include<bits/stdc++.h>

using namespace std;
const int MAX=101;
int n;

int main(){
    scanf("%d",&n);

    int os=0, cnt=0;
    vector<int> vi;
    for(int i=0;i<n;i++){
        int no;
        scanf("%d",&no);
        if(no) vi.push_back(i), cnt++;
    }
    long long ans=(vi.size() > 0 ? 1 : 0);

    for(int i=0;i<cnt-1;i++) ans *= (long long) vi[i+1]-vi[i];

    printf("%lld\n", ans);

    return 0;
}
