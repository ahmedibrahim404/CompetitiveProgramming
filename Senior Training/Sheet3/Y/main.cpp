#include<bits/stdc++.h>
using namespace std;

int a, b;
int n, x, y;
int main(){
    scanf("%d%d",&a,&b);
    set<int> st, st2;
    for(int i=1;i*i <= a;i++){
        if(a%i) continue;
        st.insert(i);st.insert(a/i);
    }

    for(int i=1;i*i <= b;i++){
        if(b%i) continue;
        if(st.find(i) != st.end()){
            st2.insert(i);
        }
        if(st.find(b/i) != st.end()){
            st2.insert(b/i);
        }
    }

    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        auto it=st2.lower_bound(y);
        if(it != st2.end() && (*it >= x && *it <= y)){
            printf("%d\n", *it);
            continue;
        }

        if(it == st2.begin()) {
            printf("-1\n");
            continue;
        }

        it--;

        if((*it >= x && *it <= y)) printf("%d\n", *it);
        else printf("-1\n");



    }




    return 0;
}
