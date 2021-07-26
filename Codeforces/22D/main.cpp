#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int n, a, b;
vpi ns;
bool took[1009];
set<int> ans;
int main(){
    scanf( "%d", &n );
    ns=vpi(n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        ns[i]=pi(a, b);
    }

    sort(ns.begin(), ns.end());

    int i=0;
    int last=ns[i].second;
    while(i<ns.size()){
        if(took[i]){
            i++;
            continue;
        }
        last=ns[i].second;

        for(int j=i+1;j<n;j++){
            if(ns[j].first > last){
                ans.insert(last);
                break;
            }
            last=min(last, ns[j].second);
            took[j]=true;
        }

        i++;

    }

    ans.insert(last);

    printf("%d\n", ans.size());
    set<int>::iterator it = ans.begin();
    while (it != ans.end()){
        printf("%d ", *it);
        it++;
    }
    return 0;
}
