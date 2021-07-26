#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int n, i1=0, i2=0, a, b;
pi l[100+9], r[100+9];
int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a > 0)r[i1].first=a, r[i1++].second=b;
        else l[i2].first=a, l[i2++].second=b;
    }

    int take=min(i1, i2)+1;
    sort(r, r+i1);
    sort(l, l+i2, greater< pair<int, int> >());

    long long total=0;
    for(int i=0;i<take;i++) total += (r[i].second)+(l[i].second);

    cout << total << endl;

    return 0;
}
